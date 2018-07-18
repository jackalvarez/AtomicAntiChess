#include <cctype>

#include "King.h"

King::King( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (islower(symbol)) ? "Black" : "White"; 
    setElementId( QString("%1King").arg(color) );
}

std::vector<COORDINATE> King::getPossibleMoves()
{
    std::vector<COORDINATE> possibleMoves;

    short x[] = { 1,1,0,-1,-1,-1,0,1 };
    short y[] = { 0,1,1,1,0,-1,-1,-1 };

    for ( int direction = 0; direction < 8; ++direction)
    {
    	short newX = currentPosition.row + x[direction];
    	short newY = currentPosition.file + y[direction];

    	if ( isFree(newX, newY)  || isEnemy(newX, newY) ) 
    		possibleMoves.push_back( COORDINATE(newX, newY) );
    }

    return possibleMoves;
}
