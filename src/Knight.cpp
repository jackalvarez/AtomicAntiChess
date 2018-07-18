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
    return possibleMoves;
}
