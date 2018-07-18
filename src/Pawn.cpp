#include <cctype>

#include "Pawn.h"

Pawn::Pawn( char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent)
    : Piece (symbol, currentPosition, board, parent)
{
    setElementId( QString("%1Pawn").arg(/*color*/ "White") );
}

std::vector<COORDINATE> Pawn::getPossibleMoves()
{
    std::vector<COORDINATE> possibleMoves;

    int direction = (this->symbol == 'P') ? -1 : 1;

    if ( currentPosition.row > 0 && currentPosition.row < 7)
    {
        // If this is the pawns first move, it can move twice
        if ( isFirstMove() )
            possibleMoves.push_back( COORDINATE(currentPosition.row+(2*direction), currentPosition.file) );
        if ( isFree(currentPosition.row+direction, currentPosition.file))
            possibleMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file) );
        if ( isEnemy(currentPosition.row+direction, currentPosition.file+1) )
            possibleMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file+1) );
        if ( isEnemy(currentPosition.row+direction, currentPosition.file-1) )
            possibleMoves.push_back( COORDINATE(currentPosition.row+direction, currentPosition.file-1) );
    }

    return possibleMoves;
}

bool Pawn::isFirstMove()
{
    // If the white pawn is in its starting position
    if ( this->symbol == 'P' && currentPosition.row == 1)
        return true;

    // If black pawn is in its starting position
    if ( this->symbol == 'p' && currentPosition.row == 6)
        return true;

    return false;
}



bool Pawn::isEnemy( short row, short column)
{
    // If the pawn is black, check if the cell is upper case
    if ( this->symbol == 'p')
        return isupper(board[row][column]->getSymbol());

    return islower(this->board[row][column]->getSymbol());
}
