#include "Piece.h"

#ifndef PAWN_H
#define PAWN_H


class Pawn : public Piece
{
  public:
    Pawn( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    std::vector<COORDINATE> getPossibleMoves();

    bool isFirstMove();
};

#endif // PAWN_H
