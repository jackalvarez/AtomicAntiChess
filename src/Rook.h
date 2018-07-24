#include "Piece.h"

#ifndef ROOK_H
#define ROOK_H


class Rook : public Piece
{
  public:
    Rook( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    QVector<Coordinates> getPossibleMoves();
};

#endif // ROOK_H
