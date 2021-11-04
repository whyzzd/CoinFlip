#ifndef MAINSCENE_H
#define MAINSCENE_H
#include<QPushButton>
#include <QMainWindow>
#include"basescene.h"
#include"mypushbutton.h"
class MainScene : public BaseScene
{
    Q_OBJECT
public:
    explicit MainScene(QWidget *parent = nullptr);
    ~MainScene();

    //控制跳转
    MyPushButton *startbtn;

    MyPushButton *startcont;

    void paintEvent(QPaintEvent*);
    void closeEvent(QCloseEvent *event);
signals:
    void closeAndSave();

};

#endif // MAINSCENE_H
