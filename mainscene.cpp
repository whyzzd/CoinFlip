#include "mainscene.h"
#include<QPainter>
#include<QLabel>
#include<QDebug>
MainScene::MainScene(QWidget *parent) : BaseScene(parent)
{

    this->setWindowTitle("开始游戏场景");
    //设置图标
    QIcon icon(":/Image/CoinIco.png");
    this->setWindowIcon(icon);

    //创建按钮对象
    startcont= new MyPushButton(":/Image/StartContinueGame.png");
    startcont->setParent(this);
    startcont->setMysize(150,150);
    startcont->move(this->width()*0.5-startcont->width()/2,this->height()-220);

    startbtn= new MyPushButton(":/Image/MenuSceneStartButton.png");
    startbtn->setParent(this);
    startbtn->setMysize(60,60);
    startbtn->move(this->width()*0.5-startbtn->width()/2,this->height()-100);

    //设置关卡文字
    QLabel *label = new QLabel;
    label->setParent(this);
    //设置位置，宽高
    label->setGeometry(30,this->height()/2-50,300,200);
    //设置字体
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    //设置文字内容
    QString str1=QString("游戏规则：\n  "
                         "点击硬币，当所有的\n"
                         "硬币都为金色时游戏\n"
                         "即可通关。\n");
    label->setText(str1);
}
MainScene::~MainScene()
{

}
void MainScene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/Image/MenuSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //放上标题
    pix.load(":/Image/Title.png");
    pix=pix.scaled(pix.width()*0.1,pix.height()*0.1);
    painter.drawPixmap(10,15,pix);

}
void MainScene::closeEvent(QCloseEvent *event)
{
//    emit closeAndSave();
    event->accept();
}
