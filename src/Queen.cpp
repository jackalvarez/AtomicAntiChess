#include <cctype>

#include "Queen.h"

Queen::Queen( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (islower(symbol)) ? "Black" : "White"; 
    setElementId( QString("%1Queen").arg(color) );
}

std::vector<COORDINATE> Queen::getPossibleMoves()
{
    return nullptr;
}

