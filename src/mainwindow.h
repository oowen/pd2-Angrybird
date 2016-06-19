#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include <QDebug>
#include <vector>
#include <QPushButton>
#include <QPixmap>

#include <gameitem.h>
#include <land.h>
#include <bird.h>
#include <blackbird.h>
#include <yellowbird.h>
#include <icebird.h>
#include <pig.h>
#include <shoot.h>
#include <barrier.h>
#include <bottom.h>
#include <thanks.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);

signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void reset();
    void wait();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QList<Pig *> PigList;
    QList<Barrier *> BarrierList;
    QList<Bird *> BirdList;
    Shoot *shoot;
    bottom *bt;
    QPoint start;
    QPoint end;
    QTimer timer;
    QTimer timer1;

};

#endif // MAINWINDOW_H
