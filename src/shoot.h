#ifndef SHOOT_H
#define SHOOT_H

#define shot_x 3.0f
#define shot_y 6.0f

#include "gameitem.h"
#include "bird.h"
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>

class Shoot : public GameItem
{
public:

    Shoot(int x, int y, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void ReadyToShoot(Bird *bird);
};

#endif // SHOOT_H
