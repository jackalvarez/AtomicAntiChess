#include "ChessManager.h"

ChessManager::ChessManager()
    : turn { 1 }
    , lastTurnPieceWasEaten { turn }
    , whitePiecesRemaining { 16 }
    , blackPiecesRemaining { 16 }
{
}

bool ChessManager::matchEnded() const
{
    return whitePiecesRemaining == 0 || blackPiecesRemaining == 0 ||
            turn - lastTurnPieceWasEaten > MAX_TURNS_WITHOUT_EATEN_PIECE;
}

void ChessManager::decreaseWhiteCount(int decreaseValue)
{
    whitePiecesRemaining -= decreaseValue;
}
void ChessManager::decreaseBlackCount(int decreaseValue)
{
    blackPiecesRemaining -= decreaseValue;
}
