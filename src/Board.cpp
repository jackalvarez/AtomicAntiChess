#include "Board.h"
#include <iostream>

#include "Pawn.h"

#define SET_PIECES(row, file, representationCharacter) \
    boardState[ (row) ][ (file) ] = new Piece( (representationCharacter), \
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

		// Fills the rows of the black pawns
		if ( row == 6 || row == 1)
		{
			for ( int col = 0; col < 8; ++col)
            {
                boardState[row][col] = ( row == 6 ? new Pawn('P', COORDINATE(6, col), boardState) :
                                                  new Pawn('p', COORDINATE(1, col), boardState) );
                if(boardState[row][col])
                    boardState[row][col]->setSharedRenderer(svgRenderer);
            }
		}
	}

	// Fill the rows 0 and 7 with the corresponding pieces

	// Black rooks
    SET_PIECES(0, 0, 'r'); SET_PIECES(0, 7, 'r');
	// Black knights
    SET_PIECES(0, 1, 'n'); SET_PIECES(0, 6, 'n');
	// Black bishops
    SET_PIECES(0, 2, 'b'); SET_PIECES(0, 5, 'b');
	// Black queen
    SET_PIECES(0, 3, 'q');
	// Black king
    SET_PIECES(0, 4, 'k');

	// White rooks
    SET_PIECES(7, 0, 'R'); SET_PIECES(7, 7, 'R');
	// White knights
    SET_PIECES(7, 1, 'N'); SET_PIECES(7, 6, 'N');
	// White bishops
    SET_PIECES(7, 2, 'B'); SET_PIECES(7, 5, 'B');
	// White queen
    SET_PIECES(7, 3, 'Q');
	// White king
    SET_PIECES(7, 4, 'K');
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
    /*for(int index = 0; index < 8; ++index)
        this->scene->addItem(boardState[1][index]);
    for(int index = 0; index < 8; ++index)
        this->scene->addItem(boardState[2][index]);*/
    boardState[6][0]->setPos(55,10);
    this->scene->addItem(boardState[6][0]);
}

void Board::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    std::cerr << "Board(" << filePosition( event->pos().x() ) << ", " << rowPosition( event->pos().y() ) << ")\n";
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
