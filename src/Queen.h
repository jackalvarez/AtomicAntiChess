#include "Piece.h"

#ifndef QUEEN_H
#define QUEEN_H


class Queen : public Piece
{
  public:
    Queen( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    QVector<Coordinates> getPossibleMoves();
};

#endif // QUEEN_H
