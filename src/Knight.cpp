#include <cctype>

#include "Knight.h"

Knight::Knight( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (islower(symbol)) ? "Black" : "White"; 
    setElementId( QString("%1Knight").arg(color) );
}

std::vector<COORDINATE> Knight::getPossibleMoves()
{
	std::vector<COORDINATE> possibleMoves;

    short x[] = { -2,-1,1,2,2,1,-1,-2 };
    short y[] = { -1,-2,-2,-1,1,2,2,1 };

    for ( int direction = 0; direction < 8; ++direction)
    {
    	short newX = currentPosition.row + x[direction];
    	short newY = currentPosition.file + y[direction];

    	if ( isFree(newX, newY)  || isEnemy(newX, newY) ) 
    		possibleMoves.push_back( COORDINATE(newX, newY) );
    }

    return possibleMoves;
}
