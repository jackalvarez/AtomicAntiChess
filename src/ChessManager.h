#ifndef CHESSMANAGER_H
#define CHESSMANAGER_H

#include <QChar>

class ChessManager
{
  private:
    /// Keeps count of the current turn of the match.
    int turn;
    /// Saves how many turns has white moved without capturing
    int whiteTurnsWithoutCapturing;
    /// Saves how many turns has black moved without capturing
    int blackTurnsWithoutCapturing;
    /// Keeps the remaining white pieces.
    int whitePiecesRemaining;
    /// Keeps the remaining black pieces.
    int blackPiecesRemaining;
    /// Stores the current state of the game. '-'  = still playing, 'W' = white won, 'B' = black won.
    QChar gameState;
    /// It defines the maximum number of turns that can pass without anyone eating a piece.
    static const int MAX_TURNS_WITHOUT_CAPTURING = 5;
  public:
    ChessManager();
    /// It returns the current turn.
    inline int getCurrentTurn() const { return turn; }
    /// It returns the remaining pieces of the white player.
    inline int getWhiteRemainingPieces() const { return whitePiecesRemaining; }
    /// It returns the remaining pieces of the black player.
    inline int getBlackRemainingPieces() const { return blackPiecesRemaining; }
    /// The game ended if one of the players doesn't have any pieces left or
    /// if five turns have passed since the last time a piece was captured.
    void setGameState();
    /// Return the current state of the game ('B', 'W', 'T' or '-')
    QChar getGameState() const;
    /// Called if a capture was made. Resets the counter of moves of that player
    void resetMovesCounter();
    /// Changes the current turn, if it is white, make it black and viceversa
    void changeTurn();
    /// Increases by one the counter of the white moves without capturing attribute
    void increaseWhiteTurnsWithoutCapturing();
    /// Increases by one the counter of the black moves without capturing attribute
    void increaseBlackTurnsWithoutCapturing();
    /// Returns the current turn of the game
    int getTurn();
    /// Decreases the count of white pieces if at least one was eaten.
    void decreaseWhiteCount(int decreaseValue);
    /// Decreases the count of black pieces if at least one was eaten.
    void decreaseBlackCount(int decreaseValue);
    /// Passes to the next turn.
    inline int operator++() { return ++turn; }
};

#endif // CHESSMANAGER_H
