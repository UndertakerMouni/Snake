#include "snake.h"
#include "ui_snake.h"

#include <QMessageBox>
#include <QTimerEvent>
#include <QPainter>
#include <QTime>
#include <QBrush>

Snake::Snake(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Snake)
{
    ui->setupUi(this);
    setFixedSize(441,462);

    head=3;                //初始化头部下标
    tail=0;                //初始化尾部下标
    node=4;                //小蛇初始节数为4节
    gamespeed=140;         //游戏速度（移动的间隔时间）
    score=0;               //初始化分数为0
    direction=6;           //小蛇的初始方向向右
    GameOver=0;            //进入游戏初始化为0
    level=1;
    length=4;
    IsPause=false;
    p=false;
    for(i=0;i<20;i++)                   //初始化游戏面板
        for(j=0;j<20;j++)
            image[i][j]=0;
    for(i=0;i<4;i++)                    //初始化小蛇初始位置
    { snake[0][i]=1;
        snake[1][i]=i+1;
    }
    for(i=1;i<=3;i++)                   //初始化小蛇坐标的显示值(即初始化小蛇显示图形对应的值)
        image[1][i]=3;
    image[1][4]=1;
    Generatefood();                                            //产生食物

    QString Level = "Level:";
    Level += QString::number(level);
    ui->label_Level->setText(Level);

    QString Score = "Score:";
    Score += QString::number(score);
    ui->label_Score->setText(Score);

    /////////////////////////////////////////
    connect(ui->action_startGame, SIGNAL(triggered()), this, SLOT(gameStart()));
    connect(ui->action_pause, SIGNAL(triggered()) ,this,  SLOT(onPause()));
    connect(ui->action_quit, SIGNAL(triggered()), this, SLOT(close()));

    connect(ui->action_veryFast, SIGNAL(triggered()), this, SLOT(superSpeed()));
    connect(ui->action_fast, SIGNAL(triggered()), this, SLOT(fastSpeed()));
    connect(ui->action_mid, SIGNAL(triggered()), this, SLOT(midSpeed()));
    connect(ui->action_slow, SIGNAL(triggered()), this, SLOT(slowSpeed()));
    connect(ui->action_verySlow, SIGNAL(triggered()), this, SLOT(verySlowSpeed()));
}

Snake::~Snake()
{
    delete ui;
}

void Snake::ReInit()
{
    head=3;                //初始化头部下标
    tail=0;                //初始化尾部下标
    node=4;                //小蛇初始节数为4节
    gamespeed=140;         //游戏速度（移动的间隔时间）
    score=0;               //初始化分数为0
    direction=6;           //小蛇的初始方向向右
    GameOver=0;            //进入游戏初始化为0
    level=1;
    length=4;
    FoodX=0;
    FoodY=0;
    snakeX=1;
    snakeY=5;
    for(i=0;i<20;i++)                   //初始化游戏面板
        for(j=0;j<20;j++)
            image[i][j]=0;
    for(i=0;i<2;i++)
        for(j=0;j<20000;j++)
            snake[i][j]=0;
    for(i=0;i<4;i++)                    //初始化小蛇初始位置
    {
        snake[0][i]=1;
        snake[1][i]=i+1;
    }
    for(i=1;i<=3;i++)                   //初始化小蛇坐标的显示值(即初始化小蛇显示图形对应的值)
        image[1][i]=3;
    image[1][4]=1;
    Generatefood();                                            //产生食物
}

//记录小蛇每次移动后头部及身体的下一坐标
int  Snake::DrawSnake()
{
    if(snakeX==FoodX && snakeY==FoodY)                                  //若小蛇头部坐标与食物坐标重叠则吃掉食物
    {
        node++;                                                           // 小蛇节数增一
        score+=10;                                                        //分数增加
        length++;
        if(length>=8)                                                     //当小蛇增长到8个时，等级加一
        {length-=8;
            level++;}
        image[snakeX][snakeY]=1;                                           //小蛇头部移动的下一位置头部图像对应的值赋给图像
        image[snake[0][head]][snake[1][head]] = 3;                         //小蛇头部其后紧跟的身体一格移动的下一位置头部图像对应的值赋给图像
        head=(head+1)%10000;
        snake[0][head] = snakeX;                                           //将小蛇头部此时的坐标值赋给记录头部坐标的snake[0][head]
        snake[1][head] = snakeY;
        Generatefood();                                                    //吃掉食物后再次随机分布食物
        // display(image,pDC);                                                         //刷新显示

    }
    else
    {
        if(!IsPause)
        {
            image[snake[0][tail]][snake[1][tail]]=0;                            //擦去小蛇尾部
            tail=(tail+1)%10000;
            image[snake[0][head]][snake[1][head]]=3;                            //小蛇头部其后紧跟的身体一格移动的下一位置头部图像对应的值赋给图像
            head=(head+1)%10000;
            snake[0][head]=snakeX;                                              //将小蛇头部此时的坐标值赋给记录头部坐标的snake[0][head]
            snake[1][head]=snakeY;
            image[snake[0][head]][snake[1][head]]=1;                            //小蛇头部移动的下一位置头部图像对应的值赋给图像
        }
        //  display(image,pDC);
    }

    return 0;
}

//使小蛇自动移动
void Snake::Automove()
{
    switch(direction)
    {
    case 6:snakeX= snake[0][head]; snakeY= snake[1][head]+1;break;          //接收到向右的信息小蛇头部Y坐标加一，X坐标不变并赋给记录头部坐标的变量
    case 4:snakeX= snake[0][head]; snakeY= snake[1][head]-1;break;         //接收到向左的信息小蛇头部Y坐标减一，X坐标不变并赋给记录头部坐标的变量
    case 8:snakeX= snake[0][head]-1; snakeY= snake[1][head];break;          //接收到向上的信息小蛇头部X坐标加一，Y坐标不变并赋给记录头部坐标的变量
    case 2:snakeX= snake[0][head]+1; snakeY= snake[1][head];break;          //接收到向下的信息小蛇头部X坐标加一，Y坐标不变并赋给记录头部坐标的变量
    default:;
    }
}

//判断游戏是否结束
int  Snake::Gameover()
{
    if(snakeX<0 || snakeX>19 ||snakeY<0 || snakeY>19)                       // 碰到墙壁游戏结束
    {
        // cout << "Game over!" << endl;
        GameOver=1;
        return GameOver;
    }
    if((image[snakeX][snakeY]!=0)&&!(snakeX==FoodX&&snakeY==FoodY))         //蛇头碰到蛇身游戏结束
    {
        // cout << "Game over!" << endl;
        if(!IsPause)
            GameOver=1;
        return GameOver;
    }
    return 0;
}

//产生食物
int  Snake::Generatefood()
{
    qsrand(QTime::currentTime().msec());                          //以时间为种子生成随机序列
    do{
        FoodX=qrand()%20;                                         //食物输出的X坐标
        FoodY=qrand()%20;                                         //食物输出的Y坐标
    }while(image[FoodX][FoodY]!=0);                               //产生的食物坐标限定在游戏面板内，且食物坐标不与小蛇身体坐标重合
    image[FoodX][FoodY]=2;
    return image[FoodX][FoodY];
}

//void display();             //显示游戏面板

//控制左移
void Snake::shiftLeft()
{
    direction = 4;
}

//控制右移
void Snake::shiftRight()
{
    direction = 6;
}

//控制下移
void Snake::shiftDown()
{
    direction = 2;
}

//控制上移
void Snake::shiftUp()
{
    direction = 8;
}
/////////////////////////////////////////////

void Snake::keyPressEvent(QKeyEvent *event)
{
   if(direction == 2 || direction == 8)
   {
       if(event->key() == Qt::Key_Right)
           shiftRight();
       else if(event->key() == Qt::Key_Left)
           shiftLeft();
       else if(event->key() == Qt::Key_0)
           onPause();

   }
   else if(direction == 4 || direction == 6)
   {
       if(event->key() == Qt::Key_Up)
           shiftUp();
       else if(event->key() == Qt::Key_Down)
           shiftDown();
       else if(event->key() == Qt::Key_0)
           onPause();
   }
}

void Snake::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == timerID)
    {
        if(!GameOver)
        {
            if(!IsPause)
                Automove();			                              // 校舍自动移动
            Gameover();                                       //判断游戏是否结束
            if(GameOver==1)
            {
                killTimer(timerID);

                if(level>8)
                    if(QMessageBox::question(this,tr("提示"),tr("你一定是骨灰级玩家！小弟佩服！还想挑战吗？"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
                    {
                        ReInit();
                        gameStart();
                    }
                    else
                        close();
                else if(level>5)
                    if(QMessageBox::question(this,tr("提示"),tr("你一定是高手！还想挑战吗？"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
                    {
                        ReInit();
                        gameStart();
                    }
                    else
                        close();
                else if(QMessageBox::question(this,tr("提示"),tr("继续努力！还想挑战吗？"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes)
                {
                    ReInit();
                    gameStart();
                }
                else
                    close();
            }
            DrawSnake();      //判断是否吃食物
        }
        this->repaint();
    }
}

void Snake::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    int nSize = 20;
    int offset = 1;
    QImage img;
    img.load(":/images/border.png");
    QBrush brushborder(img);
    painter.setBrush(brushborder);

    QRect bottomrec(0,nSize*22+offset,nSize*22,nSize);
    painter.fillRect(bottomrec,brushborder);

    QRect toprec(0,20+offset,nSize*22,nSize);
    painter.fillRect(toprec,brushborder);

    QRect leftrec(0,20+offset,nSize,nSize*21);
    painter.fillRect(leftrec,brushborder);

    QRect rightrec(nSize*21,20+offset,nSize,nSize*21);
    painter.fillRect(rightrec,brushborder);


    QRect rect(20,40+offset,nSize*20,nSize*20);
    QImage imageBack;
    imageBack.load(":/images/grass.png");
    QBrush brushBack(imageBack);
    painter.setBrush(brushBack);
    painter.drawRect(rect);

    QRect rc;
    QBrush brush(QColor(255,0,0));
    painter.setBrush(brush);

    QString Level = "Level:";
    Level += QString::number(level);
    ui->label_Level->setText(Level);

    QString Score = "Score:";
    Score += QString::number(score);
    ui->label_Score->setText(Score);

    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            rc = QRect(j*nSize+20,i*nSize+40+offset,nSize,nSize);
            if(image[i][j]!=0)
            {
                if(image[i][j]==3)
                {
                    QImage img;
                    img.load(":/images/body.png");
                    QBrush brush(img);
                    painter.setBrush(brush);
                    painter.fillRect(rc,brush);
                }
                else if(image[i][j] == 1)
                {
                    if(direction==2)
                    {
                        QImage img;
                        img.load(":/images/headdown.png");
                        QBrush brush(img);
                        painter.setBrush(brush);
                        painter.fillRect(rc,brush);
                    }
                    else if(direction == 4)
                    {
                        QImage img;
                        img.load(":/images/headleft.png");
                        QBrush brush(img);
                        painter.setBrush(brush);
                        painter.fillRect(rc,brush);
                    }
                    else if(direction == 6)
                    {
                        QImage img;
                        img.load(":/images/headright.png");
                        QBrush brush(img);
                        painter.setBrush(brush);
                        painter.fillRect(rc,brush);
                    }
                    else
                    {
                        QImage img;
                        img.load(":/images/headup.png");
                        QBrush brush(img);
                        painter.setBrush(brush);
                        painter.fillRect(rc,brush);
                    }

                }
                else if(image[i][j] == 2)
                {
                    QImage img;
                    img.load(":/images/apple.png");
                    QBrush brush(img);
                    painter.setBrush(brush);
                    painter.fillRect(rc,brush);
                }
            }

        }
    }
}

//////////////////////////////////////////////////////////////////////

void Snake::gameStart()
{
    timerID = startTimer(gamespeed);
}

void Snake::onPause()
{
    if(p)
    {
        IsPause = false;
        p = false;
    }
    else
    {
        IsPause = true;
        p = true;
    }
}

void Snake::superSpeed()
{
    gamespeed = 75;
}

void Snake::fastSpeed()
{
    gamespeed = 130;
}

void Snake::midSpeed()
{
    gamespeed = 180;
}

void Snake::slowSpeed()
{
    gamespeed = 230;
}

void Snake::verySlowSpeed()
{
    gamespeed = 300;
}
