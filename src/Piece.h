#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include <QGraphicsSvgItem>


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

public:

    explicit Piece(char symbol, Piece*** board, QGraphicsItem* parent = nullptr)
        : symbol { symbol }
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
    virtual std::vector<COORDINATE> getPossibleMoves(COORDINATE currentPosition)
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
};



#endif //PIECE_H
