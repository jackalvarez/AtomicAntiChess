#include <cctype>

#include "Piece.h"


Piece::Piece(QChar symbol, Coordinates currentPosition, Piece*** board, int health, QGraphicsItem* parent )
    : QGraphicsSvgItem { parent }
    , currentPosition { currentPosition }
    , symbol { symbol }
    , board { board }
    , health { health }
    , healthBar { new QGraphicsRectItem( currentPosition.file + 75, currentPosition.row + 15, 8, 60, this) }
{
    healthBar->setBrush(QBrush(getHealthColor()));
}

Piece::~Piece()
{
    delete healthBar;
}

QGraphicsRectItem* Piece::getHealthBar()
{
    return this->healthBar;
}

QColor Piece::getHealthColor() const
{
    switch( health)
    {
        case 1: return Qt::red;
        case 2: return Qt::yellow;
        case 3: return Qt::green;
        default: return Qt::blue;
    }
}

bool Piece::isEnemy( short row, short file)
{
    // If it is out of boundaries
    if ( row < 0 || row > 7 || file < 0 || file > 7 || board[row][file] == nullptr)
        return false;

    // If the piece is black, check if the cell is upper case
    if ( this->symbol.isLower() )
        return board[row][file]->getSymbol().isUpper();

    // Return true if the piece in the cell is the opposite color to this
    return this->board[row][file]->getSymbol().isLower();
}

bool Piece::isFree( short row, short file)
{
    // If the cell is out of boundaries, it cannot be free
	if ( row < 0 || row > 7 || file < 0 || file > 7)
		return false;

    // Return true if the cell is not occupied, 
	return (this->board[row][file] == nullptr);
}

void Piece::decreaseHealth()
{
    --this->health;
    healthBar->setBrush(getHealthColor());
}

int Piece::getHealth()
{
    return this->health;
}

void Piece::move(QPointF newPosition)
{
    this->moveAnimation = new QPropertyAnimation(this, "pos");
    this->moveAnimation->setStartValue(QPointF(pos().x(), pos().y()));
    this->moveAnimation->setEndValue(newPosition);

    // Start the animation
    this->moveAnimation->start();
}

void Piece::setPosition(Coordinates newPosition)
{
    currentPosition = newPosition;
}
