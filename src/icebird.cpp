#include "icebird.h"
#include "mainwindow.h"

icebird::icebird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):Bird(x,y,radius,timer,pixmap,world,scene)
{

}
void icebird::myability(){
    g_body->SetLinearVelocity(b2Vec2(0.01,20));
}
