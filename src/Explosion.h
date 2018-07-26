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
    QPropertyAnimation* animation;

public:
    Explosion();
    Q_OBJECT
public:
    void explode();

protected slots:
    void disappear();
};

#endif // EXPLOSION_H
