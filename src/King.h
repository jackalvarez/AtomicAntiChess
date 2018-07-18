#include "Piece.h"

#ifndef KING.h
#define KING.h


class King : public Piece
{
  public:
    King( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    std::vector<COORDINATE> getPossibleMoves();
};

#endif // KING.h