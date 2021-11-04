#ifndef MYCOIN_H
#define MYCOIN_H

#include<QTimer>
#include<QPushButton>
class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MyCoin(QWidget *parent = nullptr);
    MyCoin(QString btnImg);
    //用来改变硬币正反面的函数
    void changFlag();

    //用来记录硬币的正反面
    bool flag;

    //硬币的X坐标和Y坐标
    int posX;
    int posY;

    //执行动画的标志
    bool isAnimation=false;

    //判断是否不能点的标志(需要赋一个默认值，否则如果一开始就位true，那么硬币点不动)
    bool cantClick=false;

    //重写按下事件函数
    void mousePressEvent(QMouseEvent *event);

signals:

private:
    //创建两个定时器用于控制硬币的翻转
    QTimer *timer1;
    QTimer *timer2;

    //用来记录硬币文件名
    int m_Min=1;
    int m_Max=8;



};

#endif // MYCOIN_H
