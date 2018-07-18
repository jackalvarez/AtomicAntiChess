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
    return possibleMoves;
}

