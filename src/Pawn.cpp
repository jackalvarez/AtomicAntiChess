#include "Piece.h"

class Pawn : public Piece
{

  private:

  public:
	std::vector<COORDINATES> getPossibleMoves( char* boardState)
	{
		std::vector<COORDINATES> possibleMoves;

		if ( currentPosition.row > 0 && currentPosition.file < 7)
		{
			// If this is the pawns first move, it can move twice
			// if ( this->startingFile == currentPosition.file )
			//	possibleMoves.push_back( COORDINATES(currentPosition.file+2, currentPosition.row) );
			if ( isFree(boardState, currentPosition.file+1, currentPosition.row))
				possibleMoves.push_back( COORDINATES(currentPosition.file+1, currentPosition.row) );
			if ( isEnemy(boardState, currentPosition.file+1, currentPosition.row+1) ) 
				possibleMoves.push_back( COORDINATES(currentPosition.file+1, currentPosition.row+1) );
			if ( isEnemy(boardState, currentPosition.file+1, currentPosition.row-1) ) 
				possibleMoves.push_back( COORDINATES(currentPosition.file+1, currentPosition.row-1) );
		}

		return possibleMoves;
	}
};