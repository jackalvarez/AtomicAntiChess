#include "Piece.h"

#ifndef BISHOP_H
#define BISHOP_H


class Bishop : public Piece
{
  public:
    Bishop( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    QVector<Coordinates> getPossibleMoves();
};

#endif // BISHOP_H
