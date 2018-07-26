#include "Explosion.h"

Explosion::Explosion()
    : QObject()
    , QGraphicsPixmapItem(QPixmap(":/Explosion2_image.png").scaled(720/8,695/8))
{
}

void Explosion::explode()
{
    setScale(1);
    //this->setTransform(QTransform(3, 3, 3, 3, 1, 1));
    /*animation = new QPropertyAnimation(this, "explosion");
    animation->setStartValue(QSize(720/8,695/8));
    animation->setEndValue(QSize(720*3/8,695*3/8));
    animation->start();*/

    QTimer* timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Explosion::disappear);
    timer->start(1500);
}

void Explosion::disappear()
{
    setScale(0);
    scene()->removeItem(this);
    this->deleteLater();
}
