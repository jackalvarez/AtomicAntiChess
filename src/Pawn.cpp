#include <cctype>

#include "Pawn.h"

Pawn::Pawn( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (islower(symbol)) ? "Black" : "White";
    setElementId( QString("%1Pawn").arg(color) );
}

/*! 
* @brief Determine all of the moves in which the given pawn can move.
* @details A pawn always has a max of 5 possible moves: moving once front,
*          capturing to the left front, capturing two the right front, and 
*          two special moves, moving twice front if it is the pawn's first
*          move, and promoting to another piece if it reaches the end of 
*          the board. This method checks if those moves are available for the
*          given pawn, and if so, adds them to the corresponding vectors.
* @return a MoveTypes struct with all the valid moves that the pawn can do.
*/
std::vector<COORDINATE> Pawn::getPossibleMoves()
{
    // Stores all the possible moves for that particular pawn
    MoveTypes possibleMoves;

    // If the pawn is black, it moves up, if it is white, it moves down.
    int direction = (this->symbol == 'P') ? -1 : 1;

    // If this is the pawns first move, it can move twice front
    if ( isFirstMove() )
        possibleMoves.commutingMoves.push_back( COORDINATE(currentPosition.row+(2*direction), currentPosition.file) );\

    // If the cell in front of the pawn is empty, it can move there
    if ( isFree(currentPosition.row+direction, currentPosition.file))
        possibleMoves.commutingMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file) );
    
    // If there is an enemy to the front diagonals, the pawn can capture it
    if ( isEnemy(currentPosition.row+direction, currentPosition.file+1) )
        possibleMoves.capturingMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file+1) );
    if ( isEnemy(currentPosition.row+direction, currentPosition.file-1) )
        possibleMoves.capturingMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file-1) );

    // TODO: Add the move where a pawn can promote to another piece
    
    // Return all the possible commutingMoves and capturingMoves that the player could make with that pawn
    return possibleMoves;
}

/// Checks if the pawn is still in its starting position (meaning this is its first move).
bool Pawn::isFirstMove()
{
    // If the white pawn is in its starting position
    if ( this->symbol == 'P' && currentPosition.row == 6)
        return true;

    // If black pawn is in its starting position
    if ( this->symbol == 'p' && currentPosition.row == 1)
        return true;

    return false;
}
