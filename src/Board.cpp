#include "Board.h"


chess::board()
	: boardState { new Piece**[8] }
{
	for ( int row = 7; row >= 0; --row )
	{
		if ( (boardState[row] = Piece*[8] ) == NULL )
			return NULL;

		// Fills the rows of the black pawns
		if ( row == 6 || row == 1)
		{
			for ( int col = 0; col < 8; ++col)
				boardState[row][col] = (row==1) ? new Piece('P', board) : new Piece('p', board); 
		}
	}

	// Fill the rows 0 and 7 with the corresponding pieces

	// Black rooks
	boardState[0][0] = new Piece('r', board); boardState[0][7] = new Piece('r', board);
	// Black knights
	boardState[0][1] = new Piece('n', board); boardState[0][6] = new Piece('n', board);
	// Black bishops
	boardState[0][2] = new Piece('b', board); boardState[0][5] = new Piece('b', board);
	// Black queen
	boardState[0][3] = new Piece('q', board); 
	// Black king
	boardState[0][4] = new Piece('k', board);

	// White rooks
	boardState[7][0] = new Piece('R', board); boardState[7][7] = new Piece('R', board);
	// White knights
	boardState[7][1] = new Piece('N', board); boardState[7][6] = new Piece('N', board);
	// White bishops
	boardState[7][2] = new Piece('B', board); boardState[7][5] = new Piece('B', board);
	// White queen
	boardState[7][3] = new Piece('Q', board); 
	// White king
	boardState[7][4] = new Piece('K', board);  
}