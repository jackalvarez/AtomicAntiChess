#include "Piece.h"

#ifndef KING_H
#define KING_H


class King : public Piece
{
  public:
    King( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    std::vector<COORDINATE> getPossibleMoves();
};

#endif // KING_H
