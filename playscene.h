#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include"Basescene.h"
#include"mypushbutton.h"
#include"mycoin.h"
#include"gameconfig.h"
#include<QLabel>
#include<QDebug>

class PlayScene : public BaseScene
{
    Q_OBJECT
public:
    explicit PlayScene(QWidget *parent = nullptr);

    ~PlayScene();

    PlayScene(int levelNum);

    //控制返回跳转
    MyPushButton *retbtn;
    //控制跳转到下一关的按钮
    MyPushButton *nextlev;
    //刷新关卡按钮
    MyPushButton *reflev;
    int m_LevelNum;


    void initScene(int levelNum);

    //设置时间秒
    int sec=0;
    QTimer *sttimer;
    QString convTime(int s);

    //点击数
    int clickNum=0;
    QLabel *clicklabal;

    //重写画图事件
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *event);
    void asdas();

signals:

    //让其它场景能知道游戏已经胜利
    void isWined();

    void closeAndSave();

private:
    //维护一个数组用来存放每关的游戏数据
    int gameArr[4][4];
    //维护一个金币的二维数组
    MyCoin *coinBtn[4][4];
    //判断游戏是否胜利
    bool isWin;



};

#endif // PLAYSCENE_H
