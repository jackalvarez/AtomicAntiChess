#include <cctype>

#include "KNIGHT.H"

Knight::Knight( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (islower(symbol)) ? "Black" : "White"; 
    setElementId( QString("%1Knight").arg(color) );
}

std::vector<COORDINATE> Knight::getPossibleMoves()
{
    return nullptr;
}
