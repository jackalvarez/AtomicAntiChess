#include <cctype>

#include "Piece.h"

class Pawn : public Piece
{
  public:
    Pawn( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr)
        : Piece (symbol, currentPosition, board, parent)
    {
        setElementId( QString("%1Pawn").arg(/*color*/ "White") );
    }

	std::vector<COORDINATES> getPossibleMoves( char* boardState)
	{
		std::vector<COORDINATES> possibleMoves;

		int direction = (this->symbol == 'P') ? -1 : 1;

		if ( currentPosition.row > 0 && currentPosition.row < 7)
		{
			// If this is the pawns first move, it can move twice
			if ( isFirstMove() )
                possibleMoves.push_back( COORDINATE(currentPosition.row+(2*direction), currentPosition.file) );
			if ( isFree(currentPosition.row+direction, currentPosition.file))
                possibleMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file) );
			if ( isEnemy(currentPosition.row+direction, currentPosition.file+1) ) 
                possibleMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file+1) );
			if ( isEnemy(currentPosition.row+direction, currentPosition.file-1) ) 
                possibleMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file-1) );
		}

		return possibleMoves;
	}

	bool isFirstMove()
	{
		// If the white pawn is in its starting position
		if ( this->symbol == 'P' && currentPosition.row == 1)
			return true;

		// If black pawn is in its starting position
		if ( this->symbol == 'p' && currentPosition.row == 6)
			return true;

		return false;
	}

	inline bool isFree( short row, short column)
	{

		return this->boardState[row][column] == nullptr;
	}

	bool isEnemy( short row, short column)
	{
		// If the pawn is black, check if the cell is upper case
		if ( this->symbol == 'p')
			return isuper(boardState[row][column].symbol);

		return islower(this->boardState[row][column].symbol);
	}
};
