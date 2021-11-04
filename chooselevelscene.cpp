#include "chooselevelscene.h"
#include<QDebug>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : BaseScene(parent)
{
    this->setWindowTitle("选择关卡场景");


    //返回按钮设置
    retbtn=new MyPushButton(":/Image/BackButton.png",":/Image/BackButtonSelected.png");
    retbtn->setParent(this);
    retbtn->setMysize(50,50);
    retbtn->move(this->width()-65,this->height()-65);


    //从文件中获取数据（只有一开始进来的时候，和最后推出的时候才对文件进行操作）
    //多线程读写文件
    levcfg.moveToThread(&workThread);
    connect(this,&ChooseLevelScene::startOpenFile,&levcfg,&LevelConfig::openFile);
    //connect(&workThread,&QThread::finished,&levcfg,&QObject::deleteLater);//如果是在堆上面开辟的控件那么就要考虑这样释放
    connect(&levcfg,&LevelConfig::openResultReady,this,&ChooseLevelScene::openReceivResult);
    workThread.start();
    //发送打开文件信号
    emit startOpenFile();
    qDebug() << "The main threadID is :" << QThread::currentThreadId();



    //根据关卡数据，创建关卡按钮
    for(int i=0;i<20;i++)
    {
        choosebtn[i]=new MyPushButton(":/Image/LevelIcon.png");
        choosebtn[i]->setParent(this);
        choosebtn[i]->setMysize(40,40);
        choosebtn[i]->move(35+i%4*70,130+i/4*70);

        lockPos[i][0]=35+i%4*70;
        lockPos[i][1]=130+i/4*70;


        //当条件满足时，锁消失，可以点击
        //在图标上直接写文字效果不如 用label表示

        QLabel *label1=new QLabel;
        label1->setParent(this);
        label1->setFixedSize(choosebtn[i]->width(),choosebtn[i]->height());

        QFont font;
        //font.setFamily("华文新魏");
        font.setFamily("宋体");
        font.setPointSize(20);
        label1->setFont(font);
        label1->setText(QString::number(i+1));
        label1->move(35+i%4*70,130+i/4*70);
        //设置label上的文字居中
        label1->setAlignment(Qt::AlignCenter);
        //只做到这一步，发现点击是没有效果的
        //还需要设置让鼠标穿透label
        label1->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

    resetLock();
}

ChooseLevelScene::~ChooseLevelScene()
{

    workThread.quit();
    workThread.wait();

}

void ChooseLevelScene::resetLock(int n)
{
    //没有开放的关卡加锁
    for(int i=0;i<n;i++)
    {
        if(levcfg.getLevelLock(i)==false)
        {
            labelLock[i]=new QLabel(this);
            QPixmap tmpPix1;
            tmpPix1.load(":/Image/LevelLock.png");
            tmpPix1=tmpPix1.scaled(40,40);
            labelLock[i]->setPixmap(tmpPix1);
            labelLock[i]->setGeometry(0,0,tmpPix1.width(),tmpPix1.height());
            labelLock[i]->move(lockPos[i][0],lockPos[i][1]);
        }
    }

}
void ChooseLevelScene::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    //画背景图片
    QPixmap pix(":/Image/OtherSceneBg.png");//也可以后面再加载对象
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画标题图片
    //pix.load(":/Image/Title.png");
    //pix=pix.scaled(pix.width()*0.3,pix.height()*0.3);
    //painter.drawPixmap((this->width()-pix.width())*0.5,-70,pix.width(),pix.height(),pix);

    //放上标题
    pix.load(":/Image/Title.png");
    pix=pix.scaled(pix.width()*0.08,pix.height()*0.08);
    painter.drawPixmap(10,-22,pix);
}

void ChooseLevelScene::closeEvent(QCloseEvent *event)
{
    emit closeAndSave();
    event->accept();
}

void ChooseLevelScene::openReceivResult(const QString &str)
{
    qDebug()<<str;
}
