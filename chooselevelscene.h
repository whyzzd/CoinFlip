#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include<QPainter>
#include<QLabel>
#include<QMap>
#include<QVector>
#include"basescene.h"
#include"mypushbutton.h"
#include"globalFile.h"
#include "levelconfig.h"
#include<QThread>
class ChooseLevelScene : public BaseScene
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);
    ~ChooseLevelScene();
    //控制跳转
    MyPushButton *retbtn;
    MyPushButton *choosebtn[N];

    LevelConfig levcfg;

    QLabel *labelLock[N]={NULL};


    //初始化关卡(加上锁)
    void resetLock(int n=N);

    void paintEvent(QPaintEvent *);

    void closeEvent(QCloseEvent *event);
signals:
    void startOpenFile();
    void closeAndSave();


public slots:
    void openReceivResult(const QString &str);

private:
    QThread workThread;
    int lockPos[N][2];

};

#endif // CHOOSELEVELSCENE_H
