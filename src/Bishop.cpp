#include <cctype>

#include "Bishop.h"

Bishop::Bishop( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (islower(symbol)) ? "Black" : "White"; 
    setElementId( QString("%1Bishop").arg(color) );
}

std::vector<COORDINATE> Bishop::getPossibleMoves()
{
    std::vector<COORDINATE> possibleMoves;

    short xArray[] = { -1,1,1,-1 };
    short yArray[] = { -1,-1,1,1 };

    for ( int direction = 0; direction < 4; ++direction)
    {
    	short x = currentPosition.row + xArray[direction];
    	short y = currentPosition.file + yArray[direction];

    	while( x>=0 && x<8 && y>=0 && y<8 && isFree(x, y))
    	{
    		possibleMoves.push_back( COORDINATE(x, y) );

    		x += xArray[direction]; y += yArray[direction];
    	}

    	if( isEnemy(x,y) )
    		possibleMoves.push_back( COORDINATE(x, y) );
    }

    return possibleMoves;
}

