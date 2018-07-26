#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPropertyAnimation>
#include <QTimer>
#include <QGraphicsScene>

class Explosion : public QObject , public QGraphicsPixmapItem
{
private:
    /// Used to make the explosion grow bigger.
    QPropertyAnimation* animation;

public:
    /// Constructor.
    Explosion();
    Q_OBJECT
public:
    /// Shows the explosion for 1500ms.
    void explode();

protected slots:
    /// Sets the scale to 0, so the explosion disappears.
    void disappear();
};

#endif // EXPLOSION_H
