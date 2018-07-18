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
    return possibleMoves;
}

