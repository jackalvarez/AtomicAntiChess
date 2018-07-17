#include "Board.h"


Board::Board()
	: boardState { new Piece**[8] }
{
	for ( int row = 7; row >= 0; --row )
	{
        boardState[row] = new Piece*[8];

		// Fills the rows of the black pawns
		if ( row == 6 || row == 1)
		{
			for ( int col = 0; col < 8; ++col)
                boardState[row][col] = (row==1) ? new Piece('P', boardState) : new Piece('p', boardState);
		}
	}

	// Fill the rows 0 and 7 with the corresponding pieces

	// Black rooks
    boardState[0][0] = new Piece('r', boardState); boardState[0][7] = new Piece('r', boardState);
	// Black knights
    boardState[0][1] = new Piece('n', boardState); boardState[0][6] = new Piece('n', boardState);
	// Black bishops
    boardState[0][2] = new Piece('b', boardState); boardState[0][5] = new Piece('b', boardState);
	// Black queen
    boardState[0][3] = new Piece('q', boardState);
	// Black king
    boardState[0][4] = new Piece('k', boardState);

	// White rooks
    boardState[7][0] = new Piece('R', boardState); boardState[7][7] = new Piece('R', boardState);
	// White knights
    boardState[7][1] = new Piece('N', boardState); boardState[7][6] = new Piece('N', boardState);
	// White bishops
    boardState[7][2] = new Piece('B', boardState); boardState[7][5] = new Piece('B', boardState);
	// White queen
    boardState[7][3] = new Piece('Q', boardState);
	// White king
    boardState[7][4] = new Piece('K', boardState);
}
