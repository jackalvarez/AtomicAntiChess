#include "Piece.h"

#ifndef BISHOP_H
#define BISHOP_H


class Bishop : public Piece
{
  public:
    Bishop( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    /*!
    * @details Determine all the possible cells to which a given
    *	     bishop can move. It checks cells in four diagonals.
    * @return an std::vector with all the moves that the bishop can
    *		  do moving to the upper left, upper right, lower left
    *		  and lower right.
    */
    QVector<Coordinates> getPossibleMoves();
};

#endif // BISHOP_H
