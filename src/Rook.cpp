#include <cctype>

#include "Rook.h"

Rook::Rook( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (islower(symbol)) ? "Black" : "White"; 
    setElementId( QString("%1Rook").arg(color) );
}

std::vector<COORDINATE> Rook::getPossibleMoves()
{
    std::vector<COORDINATE> possibleMoves;

    short xArray[] = { 1,0,-1,0 };
    short yArray[] = { 0,1,0,-1 };

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
