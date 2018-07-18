#include "Piece.h"

#ifndef ROOK.H
#define ROOK.H


class Rook : public Piece
{
  public:
    Rook( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    std::vector<COORDINATE> getPossibleMoves();
};

#endif // ROOK.H