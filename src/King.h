#include "Piece.h"

#ifndef KING_H
#define KING_H

/// Creates a new Piece of type king which moves in any direction one move
class King : public Piece
{
  public:
    King( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    MoveTypes getPossibleMoves();
};

#endif // KING_H
