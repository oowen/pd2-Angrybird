#ifndef BOTTOM_H
#define BOTTOM_H
#include "gameitem.h"
#include "bird.h"
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>



class bottom :public GameItem
{
public:
    bottom(int x, int y, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // BOTTOM_H
