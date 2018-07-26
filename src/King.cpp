#include <cctype>

#include "King.h"

King::King( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, 4, parent)
{
    QString color = (symbol.isLower()) ? "Black" : "White";
    setElementId( QString("%1King").arg(color) );
}

// Method to get the possible moves for the king
// The king can move vertically, horizontally and
// diagonally in any direction, but only one square
// at a time
MoveTypes King::getPossibleMoves()
{
    MoveTypes possibleMoves;

    // The directions in which the king may go
    short x[] = { 1,1,0,-1,-1,-1,0,1 };
    short y[] = { 0,1,1,1,0,-1,-1,-1 };

    // Goes through the 8 possible directions
    for ( int direction = 0; direction < 8; ++direction)
    {
    	short newX = currentPosition.row + x[direction];
    	short newY = currentPosition.file + y[direction];

        // If the cell is free, add the move to commutingMoves
    	if ( isFree(newX, newY) ) 
            possibleMoves.commutingMoves.push_back( Coordinates(newX, newY) );

        // If the cell was occupied by an enemy, add the move to capturingMoves
        else if ( isEnemy(newX, newY) )
            possibleMoves.capturingMoves.push_back( Coordinates(newX, newY) );
    }

    return possibleMoves;
}
