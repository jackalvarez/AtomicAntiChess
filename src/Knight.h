#include "Piece.h"

#ifndef KNIGHT_H
#define KNIGHT_H


class Knight : public Piece
{
  public:
    Knight( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    MoveTypes getPossibleMoves();
};

#endif // KNIGHT_H
