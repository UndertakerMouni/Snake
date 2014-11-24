#ifndef SNAKE_H
#define SNAKE_H

#include <QMainWindow>

namespace Ui {
class Snake;
}

class Snake : public QMainWindow
{
    Q_OBJECT

public:
    explicit Snake(QWidget *parent = 0);
    ~Snake();

private:
    Ui::Snake *ui;

    int image[20][20];        //游戏面板，即小蛇活动范围
    int FoodX;                //事物出现的X坐标
    int FoodY;                //事物出现的Y坐标
    int snakeX;               //记录小蛇的头部X坐标
    int snakeY;               //记录小蛇的头部Y坐标
    int head;                 //小蛇头部下标
    int tail;                 //小蛇尾部下标
    int snake[2][20000];         //记录小蛇所有身体的坐标
    int node;                 //小蛇的节数
    int direction;            //小蛇头部的方向
    int i,j;
    int gamespeed;            //速度
    int score;                //记录分数
    bool IsPause;            //暂停
    bool p;
    int GameOver;             //使游戏结束的变量
    int level;                //设置等级
    int length;               //为了设置等级而与node一样记录设的长度
    /////////////

   // void    display(int image[20][20],CDC *pDC);
    void ReInit();
    int  DrawSnake();           //记录小蛇每次移动后头部及身体的下一坐标
    void Automove();            //使小蛇自动移动
    int  Gameover();            //判断游戏是否结束
    int  Generatefood();        //产生食物
    //void display();             //显示游戏面板
    void shiftLeft();           //控制左移
    void shiftRight();          //控制右移
    void shiftDown();           //控制下移
    void shiftUp();	            //控制上移
};

#endif // SNAKE_H
