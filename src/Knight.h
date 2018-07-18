#include "Piece.h"

#ifndef KNIGHT_H
#define KNIGHT_H


class Knight : public Piece
{
  public:
    Knight( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    std::vector<COORDINATE> getPossibleMoves();
};

#endif // KNIGHT_H
