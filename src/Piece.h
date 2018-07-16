#ifndef PIECE_H
#define PIECE_H

#include <vector>

namespace chess
{

class Piece
{

protected:
	#ifdef SECOND_COMMIT
	short health;
	short explosionDamage;
	#endif

	COORDINATE currentPosition;
	std::vector<COORDINATE> possibleMoves;
	char** board;

public:
	struct COORDINATE
	{
		short file;
		short row;

		COORDINATES(short file, short row)
		: file { file }
		, row { row }
		{}
	};

	Piece() = delete;
	Piece(char** board) : board { board } 
	{}

	Piece(std::string pieceType);
	std::vector<COORDINATES> getPossibleMoves(COORDINATES currentPosition);

	#ifdef SECOND_COMMIT
	short operator-=(short damageDealt);
	inline short getHealth();
	inline short getDamage();
	#endif

};

}

#endif //PIECE_H