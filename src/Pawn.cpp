#include <cctype>

#include "Pawn.h"

Pawn::Pawn( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    QString color = (islower(symbol)) ? "Black" : "White";
    setElementId( QString("%1Pawn").arg(color) );
}

std::vector<COORDINATE> Pawn::getPossibleMoves()
{
    MoveTypes possibleMoves;

    int direction = (this->symbol == 'P') ? -1 : 1;

    // If this is the pawns first move, it can move twice
    if ( isFirstMove() )
        possibleMoves.commutingMoves.push_back( COORDINATE(currentPosition.row+(2*direction), currentPosition.file) );
    if ( isFree(currentPosition.row+direction, currentPosition.file))
        possibleMoves.commutingMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file) );
    if ( isEnemy(currentPosition.row+direction, currentPosition.file+1) )
        possibleMoves.capturingMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file+1) );
    if ( isEnemy(currentPosition.row+direction, currentPosition.file-1) )
        possibleMoves.capturingMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file-1) );

    // TODO: Add the move where a pawn can promote to another piece
    
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
