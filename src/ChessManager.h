#ifndef CHESSMANAGER_H
#define CHESSMANAGER_H


class ChessManager
{
  private:
    /// Keeps count of the current turn of the match.
    int turn;
    /// Saves the last turn where a piece was eaten.
    int lastTurnPieceWasEaten;
    /// Keeps the remaining white pieces.
    int whitePiecesRemaining;
    /// Keeps the remaining black pieces.
    int blackPiecesRemaining;
    /// It defines the maximum number of turns that can pass without anyone eating a piece.
    static const int MAX_TURNS_WITHOUT_EATEN_PIECE = 5;
  public:
    ChessManager();
    /// It returns the current turn.
    inline int getCurrentTurn() const { return turn; }
    /// It returns the remaining pieces of the white player.
    inline int getWhiteRemainingPieces() const { return whitePiecesRemaining; }
    /// It returns the remaining pieces of the black player.
    inline int getBlackRemainingPieces() const { return blackPiecesRemaining; }
    /// The game ended if one of the players doesn't have any pieces anymore or
    /// if it has passed five turns since the last time a piece was eaten.
    bool matchEnded() const;
    /// Decreases the count of white pieces if at least one was eaten.
    void decreaseWhiteCount(int decreaseValue);
    /// Decreases the count of black pieces if at least one was eaten.
    void decreaseBlackCount(int decreaseValue);
    /// Passes to the next turn.
    inline int operator++() { return ++turn; }
};

#endif // CHESSMANAGER_H
