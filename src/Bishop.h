#include "Piece.h"

#ifndef BISHOP_H
#define BISHOP_H


class Bishop : public Piece
{
  public:
    Bishop( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    std::vector<COORDINATE> getPossibleMoves();
};

#endif // BISHOP_H
