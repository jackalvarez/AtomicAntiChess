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
	char** board;
	char symbol;

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

    explicit Piece(char** board, char symbol, QGraphicsItem* parent = nullptr)
        : QGraphicsSvgItem { parent }
        , board { board }
        , symbol { symbol }
    {
    }
    ~Piece();

    void destroy(bool removeFromScene = true, bool deleteObject = true)
    {
        if (removeFromScene) scene()->removeItem(this);
        if (deleteObject) this->deleteLater();
    }

    /*Piece(char** board) : board { board }
    {}*/

	Piece(std::string pieceType);
    virtual std::vector<COORDINATES> getPossibleMoves(COORDINATES currentPosition);

	#ifdef SECOND_COMMIT
	short operator-=(short damageDealt);
	inline short getHealth();
	inline short getDamage();
	#endif

};

}

#endif //PIECE_H
