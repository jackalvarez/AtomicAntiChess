#include <cctype>

#include "Pawn.h"

Pawn::Pawn( QChar symbol, Coordinates currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (symbol.isLower()) ? "Black" : "White";
    setElementId( QString("%1Pawn").arg(color) );
}


MoveTypes Pawn::getPossibleMoves()
{
    // Stores all the possible moves for that particular pawn
    MoveTypes possibleMoves;

    // If the pawn is black, it moves up, if it is white, it moves down.
    int direction = (this->symbol == 'P') ? -1 : 1;

    // If this is the pawns first move, it can move twice front
    if ( isFirstMove() )
        possibleMoves.commutingMoves.push_back( Coordinates(currentPosition.row+(2*direction), currentPosition.file) );\

    // If the cell in front of the pawn is empty, it can move there
    if ( isFree(currentPosition.row+direction, currentPosition.file))
        possibleMoves.commutingMoves.push_back( Coordinates(currentPosition.row+direction, currentPosition.file) );
    
    // If there is an enemy to the front diagonals, the pawn can capture it
    if ( isEnemy(currentPosition.row+direction, currentPosition.file+1) )
        possibleMoves.capturingMoves.push_back( Coordinates(currentPosition.row+direction, currentPosition.file+1) );
    if ( isEnemy(currentPosition.row+direction, currentPosition.file-1) )
        possibleMoves.capturingMoves.push_back( Coordinates(currentPosition.row+direction, currentPosition.file-1) );

    // TODO: Add the move where a pawn can promote to another piece
    
    // Return all the possible commutingMoves and capturingMoves that the player could make with that pawn
    return possibleMoves;
}

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
