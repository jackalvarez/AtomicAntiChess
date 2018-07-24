#include "Piece.h"

#ifndef KING_H
#define KING_H


class King : public Piece
{
  public:
    King( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    QVector<Coordinates> getPossibleMoves();
};

#endif // KING_H
