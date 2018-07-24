#include "Piece.h"

#ifndef PAWN_H
#define PAWN_H


class Pawn : public Piece
{
  public:
    Pawn( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    QVector<Coordinates> getPossibleMoves();

    bool isFirstMove();
};

#endif // PAWN_H
