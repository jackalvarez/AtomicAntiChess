#include <ctype>

#include "Piece.h"

class Pawn : public Piece
{
  public:
    Pawn(char** board)
        : Piece { board }
    {
        setElementId( QString("%1Pawn").arg(/*color*/ "White") );
    }

	std::vector<COORDINATES> getPossibleMoves( char* boardState)
	{
		std::vector<COORDINATES> possibleMoves;

		if ( currentPosition.row > 0 && currentPosition.file < 7)
		{
			// If this is the pawns first move, it can move twice
			if ( isFirstMove() )
				possibleMoves.push_back( COORDINATES(currentPosition.file+2, currentPosition.row) );
			if ( isFree(currentPosition.file+1, currentPosition.row))
				possibleMoves.push_back( COORDINATES(currentPosition.file+1, currentPosition.row) );
			if ( isEnemy(currentPosition.file+1, currentPosition.row+1) ) 
				possibleMoves.push_back( COORDINATES(currentPosition.file+1, currentPosition.row+1) );
			if ( isEnemy(currentPosition.file+1, currentPosition.row-1) ) 
				possibleMoves.push_back( COORDINATES(currentPosition.file+1, currentPosition.row-1) );
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
		return this->boardState[row][column] == '-';
	}

	bool isEnemy( short row, short column)
	{
		// If the pawn is black, check if the cell is upper case
		if ( this->symbol == 'p')
			return isuper(boardState[row][column]);

		return islower(this->boardState[row][column]);
	}
};
