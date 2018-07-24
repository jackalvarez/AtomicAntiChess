#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"

#include <iostream>

#include <QPointF>

#define SET_PIECES(row, file, representationCharacter, pieceType) \
    boardState[ (row) ][ (file) ] = new pieceType ( (representationCharacter), \
    COORDINATE( (row), (file) ), boardState); \
    boardState[ (row) ][ (file) ]->setSharedRenderer(svgRenderer)

Board::Board(const QPixmap &pixmap, QGraphicsItem *parent)
    : QGraphicsPixmapItem (pixmap, parent)
    , boardState { new Piece**[8] }
{
    // Load the graphic resources
    this->svgRenderer = new QSvgRenderer(QString("://Graphics_map.svg"));
	for ( int row = 7; row >= 0; --row )
	{
        boardState[row] = new Piece*[8];


        for ( int col = 0; col < 8; ++col)
        {
            // Fills the rows of the black pawns
            if ( row == 6 || row == 1)
            {
                boardState[row][col] = ( row == 6 ? new Pawn('P', Coordinates(6, col), boardState) :
                                                  new Pawn('p', Coordinates(1, col), boardState) );
                if(boardState[row][col])
                    boardState[row][col]->setSharedRenderer(svgRenderer);
            }
            else if(row != 0 && row != 7)
                boardState[row][col] = nullptr;
        }
	}

	// Fill the rows 0 and 7 with the corresponding pieces

	// Black rooks
    SET_PIECES(0, 0, 'r', Rook); SET_PIECES(0, 7, 'r', Rook);
	// Black knights
    SET_PIECES(0, 1, 'n', Knight); SET_PIECES(0, 6, 'n', Knight);
	// Black bishops
    SET_PIECES(0, 2, 'b', Bishop); SET_PIECES(0, 5, 'b', Bishop);
	// Black queen
    SET_PIECES(0, 3, 'q', Queen);
	// Black king
    SET_PIECES(0, 4, 'k', King);

	// White rooks
    SET_PIECES(7, 0, 'R', Rook); SET_PIECES(7, 7, 'R', Rook);
	// White knights
    SET_PIECES(7, 1, 'N', Knight); SET_PIECES(7, 6, 'N', Knight);
	// White bishops
    SET_PIECES(7, 2, 'B', Bishop); SET_PIECES(7, 5, 'B', Bishop);
	// White queen
    SET_PIECES(7, 3, 'Q', Queen);
	// White king
    SET_PIECES(7, 4, 'K', King);
}

Board::~Board()
{
    for(int index = 0; index < 8; ++index)
        delete[] boardState[index];
    delete[] boardState;
}

void Board::setScene(QGraphicsScene* scene)
{
    this->scene = scene;
}

void Board::addPiecesToScene()
{
#if 1
    for ( int row = 7; row >= 0; --row )
    {
        if ( row >= 6 || row <= 1)
        {
            for ( int col = 0; col < 8; ++col)
            {
                boardState[row][col]->setPos(fromCellPosToQPointF(row, col));
                this->scene->addItem(boardState[row][col]);
            }
        }
    }
#endif
#if 0
    boardState[1][0]->setPos(100, 97);
    scene->addItem(boardState[1][0]);
#endif
}

void explode(short captureRow, short captureFile)
{
    // Loops within one piece radius from the capturing square horizontally 
    for ( int row = captureRow - 1; row <= captureRow + 1; ++row )
    {
        if ( row >= 0 && row < 8)
        {
            // Loops within one piece radius from the capturing square horizontally 
            for ( int file = captureFile - 1; row <= captureFile + 1; ++file )
            {
                if ( file >= 0 && file < 8)
                    delete[] boardState[row][file];
            }
        }
    }
}

void Board::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    int colPos = filePosition( event->pos().x() ), rowPos = rowPosition( event->pos().y() );
    std::cerr << "Board(" << colPos << ", " << rowPos << ") ";
    // If there's a selected piece, then the player will try to make a move
    if(selectedPiece)
    {
        bool validMove = false;
        QVector<Coordinates> validMoves = selectedPiece->getPossibleMoves();
        std::cerr << validMoves.size();
        for(int index = 0; index < validMoves.size() && !validMove; ++index)
        {
            if(colPos == validMoves[index].file && rowPos == validMoves[index].row)
            {
                selectedPiece->move(fromCellPosToQPointF(rowPos, colPos));
                boardState[rowPos][colPos] = selectedPiece;
                selectedPiece = boardState[selectedPiece->currentY()][selectedPiece->currentX()] = nullptr;
                boardState[rowPos][colPos]->setPosition(Coordinates(rowPos, colPos));
                validMove = true;
            }
        }
    }
    // If not, the player is trying to select a piece to move
    else
    {
        // If the cell has a Piece, it keeps the pointer, else, it will have a nullptr.
        selectedPiece = boardState[rowPos][colPos];
        if(selectedPiece)
            std::cerr << "selected a piece";
    }
    std::cerr << std::endl;
}

int Board::filePosition(qreal x) const
{
    return cell(x, this->scene->width());
}
int Board::rowPosition(qreal y) const
{
    return cell(y, this->scene->height());
}

int Board::cell(qreal position, qreal dimension) const
{
    return position / (dimension / 8);
}

QPointF Board::fromCellPosToQPointF(int row, int col) const
{
    qreal rowDimension = scene->height() / 8, colDimension = scene->width() / 8;
    return QPointF( 0 + (col * colDimension), 0 + (row * rowDimension) );
}
