#include "Piece.h"

#ifndef ROOK_H
#define ROOK_H


class Rook : public Piece
{
  public:
    Rook( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    std::vector<COORDINATE> getPossibleMoves();
};

#endif // ROOK_H
