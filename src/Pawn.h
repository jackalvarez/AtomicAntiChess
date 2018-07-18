#include "Piece.h"

#ifndef PAWN_H
#define PAWN_H


class Pawn : public Piece
{
  public:
    Pawn( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    std::vector<COORDINATE> getPossibleMoves();

    bool isFirstMove();

    inline bool isFree( short row, short column)
    {

        return this->board[row][column] == nullptr;
    }

    bool isEnemy( short row, short column);
};

#endif // PAWN_H
