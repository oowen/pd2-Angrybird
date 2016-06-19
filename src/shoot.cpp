#include "shoot.h"

Shoot::Shoot(int x, int y, QPixmap pixmap, b2World *world, QGraphicsScene *scene):GameItem(world)
{
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setPos(x,y);
    scene->addItem(&g_pixmap);
}

void Shoot::ReadyToShoot(Bird *bird){
    bird->g_body->SetTransform(b2Vec2(shot_x,shot_y),0);
}
