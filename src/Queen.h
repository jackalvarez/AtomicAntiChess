#include "Piece.h"

#ifndef QUEEN_H
#define QUEEN_H


class Queen : public Piece
{
  public:
    Queen( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent = nullptr);

    /*!
    * @details Determine all the possible cells to which a given
    *	     queen can move. The queen is capable of moving both
    *		 as a rook and as a bishop (i.d., vertically, horizontally
    *		 and diagonally), so it checks for rook and bishop's moves.
    * @return a MoveTypes struct with all the moves that the queen can do.
    */
    QVector<Coordinates> getPossibleMoves();
};

#endif // QUEEN_H
