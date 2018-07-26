#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "GameEnded.h"

#include <iostream>

#include <QPointF>
#include <QtGlobal>

#define SET_PIECES(row, file, representationCharacter, pieceType) \
    boardState[ (row) ][ (file) ] = new pieceType ( (representationCharacter), \
    Coordinates( (row), (file) ), boardState); \
    boardState[ (row) ][ (file) ]->setSharedRenderer(svgRenderer)

Board::Board(const QPixmap &pixmap, Game* game, QGraphicsItem *parent)
    : QGraphicsPixmapItem (pixmap, parent)
    , boardState { new Piece**[8] }
    , turnRepresentation { new QGraphicsEllipseItem(740, 300, 100, 100) }
    , game { game }
{
    turnRepresentation->setBrush(Qt::white);
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

    for(int row = 2; row < 6; ++ row)
        for(int col = 0; col < 8; ++col)
            boardState[row][col] = nullptr;
}

Board::~Board()
{
    for(int row = 0; row < 8; ++row)
    {
        for(int file = 0; file < 8; ++file)
            delete boardState[row][file];
        delete[] boardState[row];
    }
    delete[] boardState;
    delete selectedRectangle;
}

void Board::setScene(QGraphicsScene* scene)
{
    this->scene = scene;
    this->scene->addItem(turnRepresentation);
}

void Board::addPiecesToScene()
{
    // Loops through the board
    for ( int row = 7; row >= 0; --row )
    {
        if ( row >= 6 || row <= 1)
        {
            for ( int col = 0; col < 8; ++col)
            {
                // Changes the position of the piece
                boardState[row][col]->setPos(fromCellPosToQPointF(row, col));
                this->scene->addItem(boardState[row][col]);
            }
        }
    }
}

void Board::explode(short captureRow, short captureFile)
{
    explosion = new Explosion();
    explosion->setPos(fromCellPosToQPointF(captureRow, captureFile));
    scene->addItem(explosion);
    explosion->explode();
    int row = (captureRow > 0) ? (captureRow - 1) : 0;
    int finalRow = (captureRow + 1 < 8) ? captureRow + 1 : 7;

    // Loops within one piece radius from the capturing square horizontally 
    for ( ; row <= finalRow; ++row )
    {
        int file = (captureFile) ? captureFile - 1 : 0;
        int finalFile = (captureFile + 1 < 8) ? captureFile + 1 : 7;

        // Loops within one piece radius from the capturing square horizontally 
        for ( ; file <= finalFile; ++file )
        {
            // Cell is the current piece in the cell of the board
            Piece* cell = boardState[row][file];

            // If the piece is not a nullptr
            if (cell)
            {
                // Decreases the health of the piece
                cell->decreaseHealth();

                // If the piece has not health left, delete it
                if ( cell->getHealth() == 0 )
                {
                    if ( cell->getSymbol().isLower())
                        manager.decreaseBlackCount(1);
                    else
                        manager.decreaseWhiteCount(1);

                    setExplosion(row, file);
                    delete boardState[row][file];
                    boardState[row][file] = nullptr;
                }
            }
        }
    }
}

void Board::setExplosion(int row, int file)
{
    Explosion* miniExplosion = new Explosion();
    miniExplosion->setPos(fromCellPosToQPointF(row, file));
    scene->addItem(miniExplosion);
    miniExplosion->explode();
    //miniExplosion->deleteLater();
}

void Board::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
    int colPos = filePosition( event->pos().x() ), rowPos = rowPosition( event->pos().y() );
    std::cerr << "Board(" << colPos << ", " << rowPos << ") ";
    // If there's a selected piece, then the player will try to make a move
    if(selectedPiece)
        movePieceIfPossible(rowPos, colPos);
    // If not, the player is trying to select a piece to move
    else
        savePieceIfPossible(rowPos, colPos);
}

bool Board::isRightTurn()
{
    if ( selectedPiece->getSymbol().isLower())
        return ( manager.getTurn() == 1 );

    return ( manager.getTurn() == 0 );
}
void Board::savePieceIfPossible(int rowPos, int colPos)
{
    // If the cell has a Piece, it keeps the pointer, else, it will have a nullptr.
    selectedPiece = boardState[rowPos][colPos];
    if(selectedPiece)
    {
        // Checks if the piece selected corresponds with the current turn
        if ( isRightTurn() )
        {
            validMoves = selectedPiece->getPossibleMoves();
            std::cerr << validMoves.commutingMoves.size() << '-' << validMoves.capturingMoves.size() << std::endl;

            // If there are no possible moves, then the piece shouldn't be selected.
            if(validMoves.commutingMoves.size() == 0 && validMoves.capturingMoves.size() == 0)
                selectedPiece = nullptr;
            if(selectedPiece)
            {
                selectedRectangle = new QGraphicsRectItem(colPos * 720 / 8, rowPos * 695 / 8,
                                                          720 / 8, 695 / 8);
                // Paints the rectangle light blue.
                selectedRectangle->setBrush(QBrush(QColor(0, 180, 255, 100)));
                this->scene->addItem(selectedRectangle);
            }
        }
        // If the turn wasn't correct, the piece could not be selected.
        else
        {
            selectedPiece = nullptr;
        }
    }
}

void Board::movePieceIfPossible(int rowPos, int colPos)
{
    // Allows the piece to be reselected (if the player touches another piece of the same color)
    if(boardState[rowPos][colPos] && ((selectedPiece->getSymbol().isLower() && boardState[rowPos][colPos]->getSymbol().isLower())
                                      || selectedPiece->getSymbol().isUpper() && boardState[rowPos][colPos]->getSymbol().isUpper()))
    {
        delete selectedRectangle;
        savePieceIfPossible(rowPos, colPos);
    }
    else
    {
        bool validMove = false;

        // Checks if the move made by the player was any of the commuting moves
        for(int index = 0; index < validMoves.commutingMoves.size() && !validMove; ++index)
        {
            if(colPos == validMoves.commutingMoves[index].file && rowPos == validMoves.commutingMoves[index].row)
            {
                movePiece(rowPos, colPos);
                validMove = true;

                // Adds one to the counter of the piece of moves without capturing
                if ( boardState[rowPos][colPos]->getSymbol().isUpper())
                    manager.increaseWhiteTurnsWithoutCapturing();
                else
                    manager.increaseBlackTurnsWithoutCapturing();
            }
        }

        // Checks if the move made was a capture to another piece
        for(int index = 0; index < validMoves.capturingMoves.size() && !validMove; ++index)
        {
            if(colPos == validMoves.capturingMoves[index].file && rowPos == validMoves.capturingMoves[index].row)
            {
                // If a capture was made, the piece captured is deleted
                if ( boardState[rowPos][colPos]->getSymbol().isLower())
                    manager.decreaseBlackCount(1);
                else
                    manager.decreaseWhiteCount(1);
                delete boardState[rowPos][colPos];
                boardState[rowPos][colPos] = nullptr;

                // Makes the move from the last piece to the chosen cell
                movePiece(rowPos, colPos);
                validMove = true;

                // A capture was made, the timers are resetted
                manager.resetMovesCounter();
                explode(rowPos, colPos);
            }
        }

        // If the moved chosen was a valid one
        if(validMove)
        {
            // Change turns
            manager.changeTurn();
            changeTurnRepresentation();

            // Now no pieces are selected
            delete selectedRectangle;
            selectedRectangle = nullptr;
        }
    }

    // Checks if the game ended
    manager.setGameState();
    checkIfGameEnded();
}

void Board::checkIfGameEnded()
{
    // Gets the current state of the game ('W', 'B' or '-')
    QChar gameState = manager.getGameState();

    // If the game was won by any of the players
    if(gameState == 'W' || gameState == 'B' || gameState == 'T')
    {
        QString winner;
        if(gameState == 'W')
            winner = "White player won!";
        else if(gameState == 'B')
            winner = "Black player won!";
        else
            winner = "The game was tied!";

        GameEnded* gameEnded = new GameEnded(winner);
        gameEnded->exec();

        // Closes the game
        if(gameEnded->getEndGame())
        {
            std::cerr << "Game ended\n";
            game->endGame();
        }

        // Resets the game
        else if(gameEnded->getResetGame())
        {
            std::cerr << "Reset game\n";
            game->resetGame();
        }

    }
}

void Board::movePiece(int rowPos, int colPos)
{
    // If the piece is a pawn, and it is in the last rank, a promotion move ocurred
    if ( ( selectedPiece->getSymbol() == 'P' || selectedPiece->getSymbol() == 'p') && ( rowPos == 7 || rowPos == 0 ) )
    {
        // Delete the pawn from the board
        delete boardState[selectedPiece->getPosition().row][selectedPiece->getPosition().file];

        // The new piece will be either a black or a white queen
        QChar newSymbol = (rowPos) ? 'q' : 'Q';

        // Creates the piece and assign it a Queen image
        boardState[rowPos][colPos] = selectedPiece = new Queen(newSymbol, selectedPiece->getPosition(), boardState);
        boardState[rowPos][colPos]->setSharedRenderer(svgRenderer);

        // Add the queen to the board
        scene->addItem(selectedPiece);
    }

    // Make the piece move and add it to the board
    selectedPiece->move(fromCellPosToQPointF(rowPos, colPos));
    boardState[rowPos][colPos] = selectedPiece;
    selectedPiece = boardState[selectedPiece->currentY()][selectedPiece->currentX()] = nullptr;
    boardState[rowPos][colPos]->setPosition(Coordinates(rowPos, colPos));
}

void Board::changeTurnRepresentation()
{
    turnRepresentation->brush().color() == Qt::white ? turnRepresentation->setBrush(Qt::black)
                                                     : turnRepresentation->setBrush(Qt::white);
}

int Board::filePosition(qreal x) const
{
    return cell(x, 720);
}
int Board::rowPosition(qreal y) const
{
    return cell(y, 695);
}

int Board::cell(qreal position, qreal dimension) const
{
    return position / (dimension / 8);
}

QPointF Board::fromCellPosToQPointF(int row, int col) const
{
    qreal rowDimension = 695 / 8.0, colDimension = 720 / 8.0;
    return QPointF( 0 + (col * colDimension), 0 + (row * rowDimension) );
}
