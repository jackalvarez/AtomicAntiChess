#include "Piece.h"

#ifndef ROOK_H
#define ROOK_H


class Rook : public Piece
{
  public:
    Rook( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    /*!
    * @details Determine all the possible cells to which a given
    *        rook can move. It checks cells in four directions.
    * @return an std::vector with all the moves that the rook can
    *         do, moving up, down, left and right.
    */
    QVector<Coordinates> getPossibleMoves();
};

#endif // ROOK_H
