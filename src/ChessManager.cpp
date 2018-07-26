#include "ChessManager.h"
#include <iostream>

ChessManager::ChessManager()
    : turn { 0 }
    , whitePiecesRemaining { 16 }
    , blackPiecesRemaining { 16 }
    , whiteTurnsWithoutCapturing { 0 }
    , blackTurnsWithoutCapturing { 0 }
{
}

void ChessManager::setGameState()
{
    if ( whitePiecesRemaining == 0 && blackPiecesRemaining == 0 )
    {
        gameState = 'T';
    }
    else if ( whitePiecesRemaining == 0 || blackTurnsWithoutCapturing >= MAX_TURNS_WITHOUT_CAPTURING)
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
    std::cerr << "White pieces remaining: " << whitePiecesRemaining << std::endl;
}
void ChessManager::decreaseBlackCount(int decreaseValue)
{
    blackPiecesRemaining -= decreaseValue;
    std::cerr << "Black pieces remaining: " << blackPiecesRemaining << std::endl;
}
