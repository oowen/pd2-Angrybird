#ifndef BLACKBIRD_H
#define BLACKBIRD_H

#include <gameitem.h>
#include <bird.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
class blackbird : public Bird
{
public:
    blackbird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void myability();
};

#endif // BLACKBIRD_H
