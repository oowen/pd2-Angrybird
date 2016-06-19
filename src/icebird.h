#ifndef ICEBIRD_H
#define ICEBIRD_H
#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>

class icebird:public Bird
{
public:
    icebird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void myability();
};

#endif
