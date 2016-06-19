#include "mainwindow.h"
#include "ui_mainwindow.h"

bool a=false,b=false,c=true,d=false;

int k=0;
int birdnum=0;
int wait1=0;
int t=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);

    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));

    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());

    //彈弓
    shoot = new Shoot(70,380 , QPixmap(":/image/shoot.png").scaled(50,100),world,scene);
                    //前後左右
    //功能鍵
    bottom* bt1= new bottom(20,100 , QPixmap(":/image/exit.png").scaled(60,60),world,scene);

    bottom* bt2= new bottom(20,30 , QPixmap(":/image/restart.png").scaled(60,60),world,scene);

    bottom* bt3= new bottom(30,180, QPixmap(":/image/egg.png").scaled(40,40),world,scene);

    bottom* bt4= new bottom(30,240, QPixmap(":/image/heart.png").scaled(40,40),world,scene);


    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1,32,2,QPixmap(":/ground.png").scaled(960,320),world,scene));
                        //場景高低長寬(有點不懂)

    reset();

    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));       //控制開始的timer
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);

}
void MainWindow::reset(){
    //豬豬
    Pig * pigA = new Pig(27.0,10.0, 0.5f,&timer, QPixmap(":/image/pig.png").scaled(60,60),world,scene);
    PigList.push_back(pigA);
    Pig * pigB = new Pig(15.0,10.0, 0.5f,&timer, QPixmap(":/image/pig.png").scaled(60,60),world,scene);
    PigList.push_back(pigB);
    Pig * pigC = new Pig(21.0,10.0, 0.5f,&timer, QPixmap(":/image/pig.png").scaled(60,60),world,scene);
    PigList.push_back(pigC);
    //木頭喔
    Barrier *barrierA = new Barrier(18,4,1,2,&timer,QPixmap(":/image/CANDY.png").scaled(30,150),world,scene);
    BarrierList.push_back(barrierA);
    Barrier *barrierB = new Barrier(25,2,1,0.4,&timer,QPixmap(":/image/BLOCK.png").scaled(60,60),world,scene);
    BarrierList.push_back(barrierB);
    Barrier *barrierC = new Barrier(25,4,1,0.4,&timer,QPixmap(":/image/BLOCK.png").scaled(60,60),world,scene);
    BarrierList.push_back(barrierC);
    Barrier *barrierD = new Barrier(25,6,1,0.4,&timer,QPixmap(":/image/BLOCK.png").scaled(60,60),world,scene);
    BarrierList.push_back(barrierD);
    // Create bird (You can edit here)

    //鳥
                         //(水平位置,鉛直位置,半徑                                    鳥的長寬
    Bird *birdie = new Bird(3.0f,6.0f,0.5f,&timer,QPixmap(":/bird.png").scaled(60,60),world,scene);
    BirdList.push_back(birdie);
    Bird *birdA = new blackbird (5.0f,3.3,0.5f,&timer,QPixmap(":/image/black.png").scaled(60,60),world,scene);
    BirdList.push_back(birdA);
    Bird *birdB = new yellowbird (7.0f,3.30f,0.5f,&timer,QPixmap(":/image/yellowbird.png").scaled(60,60),world,scene);
    BirdList.push_back(birdB);
    Bird *birdC = new icebird(9.0f,3.3f,0.5f,&timer,QPixmap(":/image/Ice_bird.png").scaled(60,60),world,scene);
    BirdList.push_back(birdC);


    //birdie->setLinearVelocity(b2Vec2(0,0));

    //設為靜態
    BirdList[0]->g_body->SetType(b2_staticBody);
    BirdList[1]->g_body->SetType(b2_staticBody);
    BirdList[2]->g_body->SetType(b2_staticBody);
    BirdList[3]->g_body->SetType(b2_staticBody);

    //關閉功能
    BirdList[0]->spacial=false;
    BirdList[1]->spacial=false;
    BirdList[2]->spacial=false;
    BirdList[3]->spacial=false;
    birdnum=0;
}

bool MainWindow::eventFilter(QObject *, QEvent *event)         //write something
{
    // Hint: Notice the Number of every event!

    //功能鍵雙擊
    if(event->type() == QEvent::MouseButtonDblClick){
        QMouseEvent *keyEvent = static_cast<QMouseEvent *>(event);

        if((20)<keyEvent->x() && keyEvent->x()<(80)){

            if((240)<keyEvent->y() && keyEvent->y()<(300)){
                t++;
                if(t>4){
                THANKS w;
                w.show();
                delete this;
                t=0;
                }
            }

            if((170)<keyEvent->y() && keyEvent->y()<(230)){
                //噴出很多東西
                Pig * pigA = new Pig(27.0,10.0, 0.5f,&timer, QPixmap(":/image/pig.png").scaled(60,60),world,scene);
                Pig * pigB = new Pig(15.0,10.0, 0.5f,&timer, QPixmap(":/image/pig.png").scaled(60,60),world,scene);
                Pig * pigC = new Pig(21.0,10.0, 0.5f,&timer, QPixmap(":/image/pig.png").scaled(60,60),world,scene);
                Barrier *barrierA = new Barrier(18,4,1,2,&timer,QPixmap(":/image/CANDY.png").scaled(30,150),world,scene);
                Barrier *barrierB = new Barrier(25,2,1,0.4,&timer,QPixmap(":/image/BLOCK.png").scaled(60,60),world,scene);
                Barrier *barrierC = new Barrier(25,4,1,0.4,&timer,QPixmap(":/image/BLOCK.png").scaled(60,60),world,scene);
                Barrier *barrierD = new Barrier(25,6,1,0.4,&timer,QPixmap(":/image/BLOCK.png").scaled(60,60),world,scene);

            }
            if((100)<keyEvent->y() && keyEvent->y()<(160)){
                //離開
                emit quitGame();
            }
            else if((30)<keyEvent->y() && keyEvent->y()<(90)){
                //重來
                k++;
                if(k%5==0){
                    timer.stop();
                    //清空list
                    for(int i=0;i<BarrierList.size();i++){
                            delete BarrierList[i];
                            BarrierList[i]=NULL;}
                    for(int i=0;i<PigList.size();i++){
                            delete PigList[i];
                            PigList[i]=NULL;}
                    for(int i=0;i<BirdList.size();i++){
                            delete BirdList[i];
                            BirdList[i]=NULL;}

                    BarrierList.clear();
                    PigList.clear();
                    BirdList.clear();


                    reset();
                    timer.start(100/6);
                }


            }
        }
    }

        if(event->type() == QEvent::MouseButtonPress){
            QMouseEvent *keyEvent = static_cast<QMouseEvent *>(event);
            //功能
            if(BirdList[birdnum]->spacial){
                BirdList[birdnum]->myability();
                BirdList[birdnum]->spacial=false;
                if (birdnum==3)
                d=true;
                if(birdnum<3)
                    birdnum++;
                else
                    birdnum=0;

            }
            if(c==true){
                if((90-30)<keyEvent->x() && keyEvent->x()<(90+30)){
                    if((360-30)<keyEvent->y() && keyEvent->y()<(360+30))
                    {
                        start.setX(keyEvent->x());
                        start.setY(keyEvent->y());
                        a=true;
                        c=false;
                    }
                }
            }
        }

    if (a==true){
        if(event->type() == QEvent::MouseMove)
        {
            QMouseEvent *keyEvent = static_cast<QMouseEvent *>(event);
            if (a==true&&c==false){
                float x=3.0-((start.x()-keyEvent->x())/50.0);
                float y=6.0+((start.y()-keyEvent->y())/50.0);
                BirdList[birdnum]->g_body->SetTransform(b2Vec2(x,y),0);
                b=true;

            }
        }
    }
    if (b==true&&a==true){
        if(event->type() == QEvent::MouseButtonRelease)
        {
            QMouseEvent *keyEvent = static_cast<QMouseEvent *>(event);
            if (b==true){
                end.setX(keyEvent->x());
                end.setY(keyEvent->y());
                BirdList[birdnum]->g_body->SetType(b2_dynamicBody);
                BirdList[birdnum]->setLinearVelocity(b2Vec2((start.x()-end.x())/7.5,-(start.y()-end.y())/7.5));
                BirdList[birdnum]->spacial=true;
                a=false;
                b=false;
            }

            if (birdnum==0)
                birdnum++;

                timer1.start(1000);
                timer1.connect(this,SIGNAL(timeout()),this,SLOT(wait()));
                if(wait1>3){
                    BirdList[birdnum]->g_body->SetTransform(b2Vec2(shot_x,shot_y),0);
                    timer1.stop();
                }
                wait1=0;
                c=true;
        }
    }
}
void MainWindow::wait(){
    wait1++;
}

void MainWindow::tick()
{
    world->Step(1.0/50.0,10,10);                    //(paint時距,先说下step方法，velocityIterations和positionIterations这两个参数越大，box2d就能进行更好的模拟，但是性能就会下降，这两个参数你应该自己把握以适合你的游戏。
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
    exit(1);
}



void MainWindow::on_pushButton_clicked()
{
    THANKS w;
    w.show();
}
