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
	std::vector<COORDINATE> possibleMoves;
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

	#ifdef SECOND_COMMIT
	short operator-=(short damageDealt);
	inline short getHealth();
	inline short getDamage();
	#endif

    inline char getSymbol() const { return this->symbol; }

    bool isEnemy( short row, short file);

    bool isFree(short row, short file);

    void move(QPointF newPosition);
};



#endif //PIECE_H
