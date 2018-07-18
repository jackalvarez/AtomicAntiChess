#include <cctype>

#include "Queen.h"

Queen::Queen( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (islower(symbol)) ? "Black" : "White"; 
    setElementId( QString("%1Queen").arg(color) );
}

/*! 
* @details Determine all the possible cells to which a given
*	     queen can move. The queen is capable of moving both
*		 as a rook and as a bishop (i.d., vertically, horizontally
*		 and diagonally), so it checks for rook and bishop's moves.
* @return an std::vector with all the moves that the queen can do.
*/
std::vector<COORDINATE> Queen::getPossibleMoves()
{
	// Store all the possible valid moves for the queen
    MoveTypes possibleMoves;

    // Stores the directions in which the queen can move
    short xArray[] = { 1,0,-1,0,-1,1,1,-1 };
    short yArray[] = { 0,1,0,-1,-1,-1,1,1 };

	// Loops through the 8 possible directions.
    for ( int direction = 0; direction < 8; ++direction)
    {
    	// The new x and y to check are added the direction
        short x = currentPosition.row + xArray[direction];
        short y = currentPosition.file + yArray[direction];

        // While the cell is within boundaries and is free
        while( x>=0 && x<8 && y>=0 && y<8 && isFree(x, y))
        {
        	// The move is valid, add it to possibleMoves
            possibleMoves.push_back( COORDINATE(x, y) );

            // Move the queen once more in the same direction
            x += xArray[direction]; y += yArray[direction];
        }

        // If the last cell wasn't free, but instead had an enemy
        if( isEnemy(x,y) )
            possibleMoves.push_back( COORDINATE(x, y) );
    }

    // Return all the possible valid moves the queen could make
    return possibleMoves;
}

