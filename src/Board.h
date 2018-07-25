#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QSvgRenderer>
#include <QVector>

#include "Piece.h"
#include "Score.h"


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
    ///
    Score* whiteScore = nullptr;
    ///
    Score* blackScore = nullptr;
    ///
    Piece* selectedPiece = nullptr;
    ///
    QGraphicsRectItem* selectedRectangle;
    /// Keeps the valid moves from the last selected piece.
    MoveTypes validMoves;

public:
	// Constructor. Creates the board for a game in the starting position.
    explicit Board(const QPixmap& pixmap, QGraphicsItem* parent = nullptr);

    ~Board();

	// Makes sure that a given move is done an the board state is changed
	void makeMove();

	/*! 
    * @brief Explodes all the pieces surrounding a given cell.
    * @details After a capture is made, this method is called so that all the
    *		   pieces whithin one piece radius from the capturing square, are
    *	       removed from the board. The board state will then have nullptr
    *		   in those cells.
    * @param captureRow The row where the capture was made.
    * @param captureFile The file where the capture was made.
    */
	void explode(short captureRow, short captureFile);
	
    ///
    virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

    ///
    void savePieceIfPossible(int rowPos, int colPos);

    ///
    void movePieceIfPossible(int rowPos, int colPos);

    ///
    void movePiece(int rowPos, int colPos);

    void setScene(QGraphicsScene* scene);

    void addPiecesToScene();

    int filePosition(qreal x) const;
    int rowPosition(qreal y) const;
    int cell(qreal position, qreal dimension) const;
    QPointF fromCellPosToQPointF(int row, int col) const;
private:

};



#endif // BOARD_H
