KNIGHT.H

#include "Piece.h"

#ifndef KNIGHT.H
#define KNIGHT.H


class Knight : public Piece
{
  public:
    Knight( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    std::vector<COORDINATE> getPossibleMoves();
};

#endif // KNIGHT.H