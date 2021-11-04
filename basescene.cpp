#include "basescene.h"
#include<QMenuBar>
#include<QImage>
BaseScene::BaseScene(QWidget *parent) : QMainWindow(parent)
{

    QIcon icon(":/Image/CoinIco.png");
    this->setWindowIcon(icon);
    //设置尺寸
    setFixedSize(320,600);

    //创建菜单栏
    QMenuBar *bar=menuBar();
    setMenuBar(bar);

    QMenu *startMenu=bar->addMenu("管理");
    QAction* quit=startMenu->addAction("退出");
    connect(quit,&QAction::triggered,[=](){
        this->close();
    });



    QMenu *tipMenu=bar->addMenu("太难了？");
    QAction* showRaiders=tipMenu->addAction("秘笈");
    connect(showRaiders,&QAction::triggered,[=](){
        QWidget *pic=new QWidget;
        QImage img(":/Image/Raiders.png");
        pic->setFixedSize(img.width(),img.height());

        //pic->setStyleSheet("border-image:url(:/Image/Raiders.png);");
        pic->setStyleSheet("background-image:url(:/Image/Raiders.png);");
        pic->show();
    });
}
