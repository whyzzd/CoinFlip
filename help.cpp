#include "help.h"
#include<QPainter>
Help::Help(QWidget *parent) : QWidget(parent)
{

}
void Help::paintEvent(QPaintEvent *event)
{
    //加载背景图片
    QPainter painter(this);
    QPixmap pix(":/Image/Raiders.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
