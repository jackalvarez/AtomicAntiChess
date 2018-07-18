#include <cctype>

#include "Rook.h"

Rook::Rook( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (islower(symbol)) ? "Black" : "White"; 
    setElementId( QString("%1Rook").arg(color) );
}

/*! 
* @brief Determine all the possible cells to which a given
*        rook can move. It checks cells in four directions.
* @return an std::vector with all the moves that the rook can
*         do, moving up, down, left and right.
*/
std::vector<COORDINATE> Rook::getPossibleMoves()
{
    // Store all the possible valid moves for the rook
    std::vector<COORDINATE> possibleMoves;

    // Stores the directions in which the rook can move
    short xArray[] = { 1,0,-1,0 };
    short yArray[] = { 0,1,0,-1 };

    // Loops through the 4 possible directions.
    for ( int direction = 0; direction < 4; ++direction)
    {
        // The new x and y to check are added the direction
        short x = currentPosition.row + xArray[direction];
        short y = currentPosition.file + yArray[direction];

        // While the cell is within boundaries and is free
        while( x>=0 && x<8 && y>=0 && y<8 && isFree(x, y))
        {
            // The move is valid, add it to possibleMoves
            possibleMoves.push_back( COORDINATE(x, y) );

            // Move the rook once more in the same direction
            x += xArray[direction]; y += yArray[direction];
        }

        // If the last cell wasn't free, but instead had an enemy
        if( isEnemy(x,y) )
            possibleMoves.push_back( COORDINATE(x, y) );
    }

    // Return all the possible valid moves the rook could make
    return possibleMoves;
}