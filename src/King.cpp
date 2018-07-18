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
    MoveTypes possibleMoves;

    short x[] = { 1,1,0,-1,-1,-1,0,1 };
    short y[] = { 0,1,1,1,0,-1,-1,-1 };

    for ( int direction = 0; direction < 8; ++direction)
    {
    	short newX = currentPosition.row + x[direction];
    	short newY = currentPosition.file + y[direction];

    	if ( isFree(newX, newY) ) 
    		possibleMoves.commutingMoves.push_back( COORDINATE(newX, newY) );
        else if ( isEnemy(newX, newY) )
            possibleMoves.capturingMoves.push_back( COORDINATE(newX, newY) );
    }

    return possibleMoves;
}
