#include "playscene.h"
#include<QPropertyAnimation>
#include<QPainter>
#include<QDebug>
PlayScene::PlayScene(QWidget *parent) : BaseScene(parent)
{

}


PlayScene::PlayScene(int levelNum)
{
    initScene(levelNum);
}

void PlayScene::initScene(int levelNum)
{
    this->setWindowTitle("游戏场景");
    this->m_LevelNum=levelNum;
    QString str=QString("当前选择的关卡是%1关").arg(levelNum);

    //返回按钮设置
    retbtn=new MyPushButton(":/Image/BackButton.png",":/Image/BackButtonSelected.png");
    retbtn->setParent(this);
    retbtn->setMysize(50,50);
    retbtn->move(this->width()-65,this->height()-65);

    //下一关的按钮设置
    nextlev=new MyPushButton(":/Image/NextLevel.png",":/Image/NextLevelSelected.png");
    nextlev->setParent(this);
    nextlev->setMysize(50,50);
    nextlev->move(this->width()-200,this->height()-150);
    //上一关的按钮设置
    nextlev=new MyPushButton(":/Image/LastLevel.png",":/Image/LastLevelSelected.png");
    nextlev->setParent(this);
    nextlev->setMysize(50,50);
    nextlev->move(this->width()-270,this->height()-150);
    //刷新关卡按钮
    reflev=new MyPushButton(":/Image/RefreshLevel.png",":/Image/RefreshSelected.png");
    reflev->setParent(this);
    reflev->setMysize(50,50);
    reflev->move(this->width()-100,this->height()-150);


    //设置关卡文字
    QLabel *label = new QLabel;
    label->setParent(this);
    //设置位置，宽高
    label->setGeometry(80,this->height()-70,120,50);
    //设置字体
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QPalette pa;
    pa.setColor(QPalette::WindowText,Qt::white);
    label->setPalette(pa);
    //设置文字内容
    QString str1=QString("第%1关").arg(this->m_LevelNum);
    label->setText(str1);

    //使用一个数组来接收来自gameconfig中第n关的数据
    GameConfig game;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            gameArr[i][j]=game.mData[this->m_LevelNum][i][j];
        }
    }

    //设置大金币标题动画
    QPixmap pix(":/Image/Title.png");
    QLabel *titlelabel=new QLabel(this);
    pix=pix.scaled(pix.width()*0.08,pix.height()*0.08);
    titlelabel->setGeometry(0,40,pix.width(),pix.height());
    titlelabel->setPixmap(pix);
    QPropertyAnimation *animation1=new QPropertyAnimation(titlelabel,"geometry");
    animation1->setDuration(2000);
    //设置开始位置
    animation1->setStartValue(QRect(titlelabel->x(),titlelabel->y(),titlelabel->width(),titlelabel->height()));
    //设置结束位置
    animation1->setEndValue(QRect(titlelabel->x(),titlelabel->y()+10,titlelabel->width(),titlelabel->height()));
    //设置缓和曲线
    animation1->setEasingCurve(QEasingCurve::OutInBounce);
    QTimer *timer=new QTimer(this);
    timer->start(2000);
    connect(timer,&QTimer::timeout,[=](){
            animation1->start();
    });

    //设置时间显示
    sttimer=new QTimer(this);
    QLabel *stlabal=new QLabel(this);
    QFont tfont;
    tfont.setFamily("华文新魏");
    tfont.setPointSize(15);
    tfont.setBold(true);
    stlabal->setFont(tfont);
    QPalette tpa;
    tpa.setColor(QPalette::WindowText,Qt::white);
    stlabal->setPalette(tpa);
    stlabal->setGeometry(100,60,180,30);
    stlabal->setText(QString("时间："+convTime(sec++)));
    sttimer->start(1000);
    connect(sttimer,&QTimer::timeout,[=](){
        QString s=convTime(sec++);
        stlabal->setText(QString("时间："+s));
    });


    //设置胜利图片
    QLabel *winLabel1=new QLabel(this);
    QPixmap tmpPix1;
    tmpPix1.load(":/Image/LevelCompletedDialogBg1.png");
    tmpPix1=tmpPix1.scaled(220,120);
    winLabel1->setPixmap(tmpPix1);
    winLabel1->setGeometry(0,0,tmpPix1.width(),tmpPix1.height());
    winLabel1->move((this->width()-220)*0.5,-150);

    //点击数显示
    clicklabal=new QLabel(this);
    clicklabal->setFont(tfont);
    clicklabal->setPalette(tpa);
    clicklabal->setGeometry(100,100,150,30);
    clicklabal->setText(QString("所翻次数："+QString::number(clickNum++)));

    //设置金币背景
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            QPixmap pix=QPixmap(":/Image/BoardNode.jpg");
            pix=pix.scaled(45,45);
            QLabel *label = new QLabel(this);

            label->setPixmap(pix);
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setParent(this);
            label->move(62+i*50,200+j*50);

            //加载翻币按钮
             QString str0="";
            if(gameArr[i][j]==1)
            {
                str0=":/Image/Coin0001.png";
            }
            else
            {
                str0=":/Image/Coin0008.png";
            }
            MyCoin *myc=new MyCoin(str0);
            myc->setParent(this);
            myc->move(62+i*50,200+j*50);
            //将硬币的正反面初始化
            myc->flag=gameArr[i][j];
            //将每个硬币的坐标初始化
            myc->posX=i;
            myc->posY=j;
            //将金币对象放进金币数组当中
            this->coinBtn[i][j]=myc;
            //监听点击事件
            connect(myc,&QPushButton::clicked,[=](){
                clicklabal->setText(QString("所翻次数："+QString::number(clickNum++)));

                //在点击完之后就禁用点击
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        this->coinBtn[i][j]->cantClick=true;
                    }
                }
                //调用改变硬币正反面函数
                myc->changFlag();

                //将维护的数组中的值也改变
                gameArr[i][j]=myc->flag?0:1;

                //延时翻转周围的金币
                QTimer::singleShot(300,this,[=](){
                    //翻转周围的硬币
                    if(myc->posX+1<=3)//右
                    {
                        this->coinBtn[myc->posX+1][myc->posY]->changFlag();
                        gameArr[myc->posX+1][myc->posY]=gameArr[myc->posX+1][myc->posY]?0:1;
                    }
                    if(myc->posX-1>=0)//左
                    {
                        this->coinBtn[myc->posX-1][myc->posY]->changFlag();
                        gameArr[myc->posX-1][myc->posY]=gameArr[myc->posX-1][myc->posY]?0:1;
                    }
                    if(myc->posY+1<=3)//上
                    {
                        this->coinBtn[myc->posX][myc->posY+1]->changFlag();
                        gameArr[myc->posX][myc->posY+1]=gameArr[myc->posX][myc->posY+1]?0:1;
                    }
                    if(myc->posY-1>=0)//下
                    {
                        this->coinBtn[myc->posX][myc->posY-1]->changFlag();
                        gameArr[myc->posX][myc->posY-1]=gameArr[myc->posX][myc->posY-1]?0:1;
                    }

                    //在硬币翻完之后就开启点击
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            this->coinBtn[i][j]->cantClick=false;
                        }
                    }

                    this->isWin=true;
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            if(this->coinBtn[i][j]->flag==false)
                            {
                                this->isWin=false;
                            }
                        }
                    }
                    if(this->isWin==true)
                    {
                        emit isWined();
                        for(int i=0;i<4;i++)
                        {
                            for(int j=0;j<4;j++)
                            {
                                this->coinBtn[i][j]->cantClick=true;
                            }
                        }

                        //将胜利的图片放下来
                        QPropertyAnimation *animation=new QPropertyAnimation(winLabel1,"geometry");
                        animation->setDuration(1000);
                        //设置开始位置
                        animation->setStartValue(QRect(winLabel1->x(),winLabel1->y(),winLabel1->width(),winLabel1->height()));
                        //设置结束位置
                        animation->setEndValue(QRect(winLabel1->x(),winLabel1->y()+390,winLabel1->width(),winLabel1->height()));
                        //设置缓和曲线
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        animation->start();

                        winLabel1->raise();
                        //设置胜利图片
                        //QLabel *winLabel2=new QLabel(this);
                        QTimer::singleShot(800,this,[=](){
                            QPixmap tmpPix2;
                            tmpPix2.load(":/Image/LevelCompletedDialogBg2.png");
                            tmpPix2=tmpPix2.scaled(220,120);
                            winLabel1->setPixmap(tmpPix2);

                            winLabel1->setGeometry(winLabel1->x(),winLabel1->y(),winLabel1->width(),winLabel1->height());

                        });
                    }
                });

            });

        }
    }
}
PlayScene::~PlayScene()
{

}

QString PlayScene::convTime(int s)
{
    int H = s / (60*60);
    int M = (s- (H * 60 * 60)) / 60;
    int S = (s - (H * 60 * 60)) - M * 60;
    QString hour = QString::number(H);
    if (hour.length() == 1) hour = "0" + hour;
    QString min = QString::number(M);
    if (min.length() == 1) min = "0" + min;
    QString sec = QString::number(S);
    if (sec.length() == 1) sec = "0" + sec;
    QString qTime = hour + " : " + min + " : " + sec;
    return qTime;
}
void PlayScene::paintEvent(QPaintEvent *)
{
    //加载背景图片
    QPainter painter(this);
    QPixmap pix(":/Image/PlayLevelScene.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //放上标题
//    pix.load(":/Image/Title.png");
//    pix=pix.scaled(pix.width()*0.1,pix.height()*0.1);
//    painter.drawPixmap(10,15,pix);
}
void PlayScene::closeEvent(QCloseEvent *event)
{
    emit closeAndSave();
    event->accept();
}
