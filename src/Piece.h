#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include <QGraphicsSvgItem>
#include <QPropertyAnimation>


struct COORDINATE
{
    short row;
    short file;

    COORDINATE(short row = 0, short file = 0)
    : row { row }
    , file { file }
    {}
};

class Piece : public QGraphicsSvgItem
{
    Q_OBJECT

    //Maybe
    //Q_DISABLE_COPY(Piece)

protected:
	#ifdef SECOND_COMMIT
	short health;
	short explosionDamage;
	#endif

	COORDINATE currentPosition;

    struct MoveTypes
    {
        std::vector<COORDINATE> commutingMoves;
        std::vector<COORDINATE> capturingMoves;       
    };

    MoveTypes possibleMoves;
	char symbol;
    Piece*** board;
    QPropertyAnimation* moveAnimation = nullptr;

public:

    explicit Piece(char symbol, COORDINATE currentPosition, Piece*** board, QGraphicsItem* parent = nullptr)
        : symbol { symbol }
        , currentPosition { currentPosition }
        , board { board }
        , QGraphicsSvgItem { parent }
        
    {
    }
    
    ~Piece()
    {
    }
#if 0
    void destroy(bool removeFromScene = true, bool deleteObject = true)
    {
        if (removeFromScene) scene()->removeItem(this);
        if (deleteObject) this->deleteLater();
    }
#endif
    virtual std::vector<COORDINATE> getPossibleMoves()
    {
        std::vector<COORDINATE> possibleMoves;
        return possibleMoves;
    }

    /*! 
    * @brief Checks if a given cell in the board is empty.
    * @param row The row to check in the board.
    * @param file The file to check in the board.
    * @return true if the given cell is a nullptr (there is no piece).
    */
    bool isFree(short row, short file);

    /*! 
    * @brief Checks if a given cell has a piece that belongs to the opponent.
    *        As White pieces are uppercase and black pieces lower case, if this
    *        symbol is upper case, it has to check if the other's symbol is 
    *        lower case, and viceversa.
    * @param row The row to check in the board.
    * @param file The file to check in the board.
    * @return true if the color of the piece in the coordinates given
    *         is opposite to "this" piece's color.
    *         false if it has the same color or is empty.
    */
    bool isEnemy( short row, short file);

    void move(QPointF newPosition);

    #ifdef SECOND_COMMIT
    short operator-=(short damageDealt);
    inline short getHealth();
    inline short getDamage();
    #endif

    inline char getSymbol() const { return this->symbol; }

    inline int currentX() const { return currentPosition.file; }
    inline int currentY() const { return currentPosition.row; }

    inline void setPosition(COORDINATE newPosition) { currentPosition = newPosition; }
};



#endif //PIECE_H
