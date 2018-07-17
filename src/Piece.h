#ifndef PIECE_H
#define PIECE_H

#include <vector>

#include <QGraphicsSvgItem>

namespace chess
{

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
	Piece** board;

public:
	struct COORDINATE
	{
		short file;
		short row;

		COORDINATES(short file, short row)
		: file { file }
		, row { row }
		{}
	};

    explicit Piece(char symbol, Piece** board, QGraphicsItem* parent = nullptr)
        : symbol { symbol }
        , board { board }
        , QGraphicsSvgItem { parent }
        
    {
    }
    
    ~Piece();

    void destroy(bool removeFromScene = true, bool deleteObject = true)
    {
        if (removeFromScene) scene()->removeItem(this);
        if (deleteObject) this->deleteLater();
    }

    virtual std::vector<COORDINATES> getPossibleMoves(COORDINATES currentPosition);

	#ifdef SECOND_COMMIT
	short operator-=(short damageDealt);
	inline short getHealth();
	inline short getDamage();
	#endif

};

}

#endif //PIECE_H
