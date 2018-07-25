#include "ChessManager.h"

ChessManager::ChessManager()
    : turn { 0 }
    , whitePiecesRemaining { 16 }
    , blackPiecesRemaining { 16 }
{
}

void ChessManager::setGameState()
{
    if ( whitePiecesRemaining == 0 || blackTurnsWithoutCapturing >= MAX_TURNS_WITHOUT_CAPTURING)
    {
        gameState = 'W';
    }
    else if ( blackPiecesRemaining == 0 || whiteTurnsWithoutCapturing >= MAX_TURNS_WITHOUT_CAPTURING)
    {
        gameState = 'B';
    }
    else
    {
        gameState = '-';
    }
}

QChar ChessManager::getGameState() const
{
    return this->gameState;
}

void ChessManager::resetMovesCounter()
{
    // If its the black pieces turn (1)
    if ( turn )
        blackTurnsWithoutCapturing = 0;
    else
        whiteTurnsWithoutCapturing = 0;
}

void ChessManager::changeTurn()
{
    turn = (turn) ? 0 : 1;
}

int ChessManager::getTurn()
{
    return this->turn;
}

void ChessManager::decreaseWhiteCount(int decreaseValue)
{
    whitePiecesRemaining -= decreaseValue;
}
void ChessManager::decreaseBlackCount(int decreaseValue)
{
    blackPiecesRemaining -= decreaseValue;
}
