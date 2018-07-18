#include "Piece.h"

#ifndef QUEEN_H
#define QUEEN_H


class Queen : public Piece
{
  public:
    Queen( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    std::vector<COORDINATE> getPossibleMoves();
};

#endif // QUEEN_H