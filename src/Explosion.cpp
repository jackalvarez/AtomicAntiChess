#include "Explosion.h"

Explosion::Explosion()
    : QObject()
    , QGraphicsPixmapItem(QPixmap(":/Explosion2_image.png").scaled(720/8,695/8))
{
}

void Explosion::explode()
{
    setScale(1);

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
