#include <cctype>

#include "Piece.h"

bool Piece::isEnemy( short row, short file)
{
    // If the piece is black, check if the cell is upper case
    if ( islower(this->symbol) )
        return isupper(board[row][file]->getSymbol());

    return islower(this->board[row][file]->getSymbol());
}

bool Piece::isFree( short row, short file)
{
	if ( row < 0 || row > 7 || file < 0 || file > 7)
		return false;
	return (this->board[row][file] == nullptr);
}