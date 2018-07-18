#include <cctype>

#include "Piece.h"

bool Piece::isEnemy( short row, short file)
{
    // If it is out of boundaries
    if ( row < 0 || row > 7 || file < 0 || file > 7)
        return false;

    // If the piece is black, check if the cell is upper case
    if ( islower(this->symbol) )
        return isupper(board[row][file]->getSymbol());

    // Return true if the piece in the cell is the opposite color to this
    return islower(this->board[row][file]->getSymbol());
}

bool Piece::isFree( short row, short file)
{
    // If the cell is out of boundaries, it cannot be free
	if ( row < 0 || row > 7 || file < 0 || file > 7)
		return false;

    // Return true if the cell is not occupied, 
	return (this->board[row][file] == nullptr);
}

void Piece::move(QPointF newPosition)
{
    this->moveAnimation = new QPropertyAnimation(this, "pos");
    this->moveAnimation->setStartValue(QPointF(0,0));
    this->moveAnimation->setEndValue(newPosition);

    // Start the animation
    this->moveAnimation->start();
}
