#include "Piece.h"

#ifndef BISHOP.H
#define BISHOP.H


class Bishop : public Piece
{
  public:
    Bishop( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    std::vector<COORDINATE> getPossibleMoves();
};

#endif // BISHOP.H