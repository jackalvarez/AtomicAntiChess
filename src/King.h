#include "Piece.h"

#ifndef KING_H
#define KING_H


class King : public Piece
{
  public:
    King( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    MoveTypes getPossibleMoves();
};

#endif // KING_H
