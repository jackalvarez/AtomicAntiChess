#include <cctype>

#include "BISHOP.H"

Bishop::Bishop( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (islower(symbol)) ? "Black" : "White"; 
    setElementId( QString("%1Bishop").arg(color) );
}

std::vector<COORDINATE> Bishop::getPossibleMoves()
{
    return nullptr;
}

