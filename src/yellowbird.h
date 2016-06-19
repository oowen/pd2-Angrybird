#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H

#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
class yellowbird: public Bird
{
public:
    yellowbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void myability();

};

#endif // YELLOWBIRD_H
