#include "snake.h"
#include "ui_snake.h"

Snake::Snake(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Snake)
{
    ui->setupUi(this);

    head=3;                //初始化头部下标
    tail=0;                //初始化尾部下标
    node=4;                //小蛇初始节数为4节
    gamespeed=140;         //游戏速度（移动的间隔时间）
    score=0;               //初始化分数为0
    direction=6;           //小蛇的初始方向向右
    GameOver=0;            //进入游戏初始化为0
    level=1;
    length=4;
    IsPause=FALSE;
    p=FALSE;
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


    /////////////////////////////////////////


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
    qsrand(time(0));                                               //以时间为种子生成随机序列
    do{
        FoodX=rand()%20;                                             //食物输出的X坐标
        FoodY=rand()%20;                                             //食物输出的Y坐标
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
    direction = 8;
}

//控制上移
void Snake::shiftUp()
{
    direction = 2;
}
