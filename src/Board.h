#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QSvgRenderer>

#include <vector>

#include "Piece.h"


#define SECOND_COMMIT 0

class Board : public QGraphicsPixmapItem
{
    //Q_OBJECT
    Q_DISABLE_COPY(Board)
private: 
	/* The matrix to store the state of the board as characters.
	 * Notation: 
	 *	K = King
	 * 	Q = Queen
	 * 	R = Rook
	 *	N = Knight
	 *	B = Bishop
	 *	P = Pawn
	 *
	 * If the letter is upper case, it means it is a white piece. If the letter
	 * is lower case, it is a black piece. For example, "'K' | 'p' | 'N'" would 
	 * mean there is a black pawn between the white king and a white night.	
	*/
    Piece*** boardState;
    QGraphicsScene* scene;
    /// Parsers the assets svg file
    QSvgRenderer* svgRenderer = nullptr;

public:
	// Constructor. Creates the board for a game in the starting position.
    explicit Board(const QPixmap& pixmap, QGraphicsItem* parent = nullptr);

    ~Board();
	// Makes sure that a given move is done an the board state is changed
	void makeMove();
	
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

    void setScene(QGraphicsScene* scene);

    void addPiecesToScene();

    int filePosition(qreal x) const;
    int rowPosition(qreal y) const;
    int cell(qreal position, qreal dimension) const;
private:

};



#endif // BOARD_H
