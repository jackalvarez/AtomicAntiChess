#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "Piece.h"

#define SECOND_COMMIT 0

class board
{

private: 
	/* The matrix to store the state of the board as characters.
	 * Notation: 
	 *	K = King
	 * 	Q = Queen
	 * 	R = Rook
	 *	N = Knight
	 *	B = Bishop
	 *	P = Pawn
	 *
	 * If the letter is upper case, it means it is a white piece. If the letter
	 * is lower case, it is a black piece. For example, "'K' | 'p' | 'N'" would 
	 * mean there is a black pawn between the white king and a white night.	
	*/
	char** boardState;

public:
	// Constructor. Creates the board for a game in the starting position.
	explicit board();

	// Makes sure that a given move is done an the board state is changed
	void makeMove();
	

private:

};



#endif // BOARD_H