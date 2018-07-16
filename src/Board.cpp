#include "Board.h"


chess::board()
	: (char**) malloc(8)
{
	for ( int row = 7; row >= 0; --row )
	{
		if ( (boardState[row] = (char*)malloc(columns) ) == NULL )
			return NULL;

		// Fills the rows of the black pawns
		if ( row == 6 || row == 1)
		{
			for ( int col = 0; col < 8; ++col)
				boardState[row][col] = (row==1) ? 'P' : 'p'; 
		}
	}

	// TODO: Fill the rows 0 and 7 with the corresponding pieces
}