#include "scenemanager.h"
#include<QTimer>
#include<QDebug>
#include<iostream>

using namespace  std;
SceneManager::SceneManager(QObject *parent) : QObject(parent)
{
    mains=new MainScene;

    chooses=new ChooseLevelScene;
    //plays=new PlayScene;

    //如果刚开始没有存档文件，那么应该没有继续游戏按钮
    if(!chooses->levcfg.hasSaveFile)
    {
        mains->startcont->hide();
    }

    mains->show();

    //主场景跳转===>选择关卡场景(继续游戏)
    connect(mains->startcont,&QPushButton::clicked,[=](){
        mains->startcont->zoom1();
        mains->startcont->zoom2();
        QTimer::singleShot(200,this,[=](){
            mains->hide();
            chooses->move(mains->x(),mains->y());
            chooses->show();
        });
    });
    //主场景跳转====>选择关卡场景(新开始游戏)
    connect(mains->startbtn,&QPushButton::clicked,[=](){
        mains->startbtn->zoom1();
        mains->startbtn->zoom2();
        QTimer::singleShot(200,this,[=](){
            mains->hide();
            mains->startcont->show();


            //判断当前的关卡是多少，以便重置关卡锁
            int levnum=nowLevelNum();
            chooses->levcfg.initLevel();
            chooses->resetLock(levnum);


            chooses->move(mains->x(),mains->y());
            chooses->show();
        });
    });

    //选择关卡场景===>跳转到主场景
    connect(chooses->retbtn,&QPushButton::clicked,[=](){
        chooses->retbtn->zoom1();
        chooses->retbtn->zoom2();
        QTimer::singleShot(200,this,[=](){
            chooses->hide();
            mains->move(chooses->x(),chooses->y());
            mains->show();
        });
    });

    //选择关卡场景===>游戏场景
    for(int i=0;i<N;i++)
    {
        connect(chooses->choosebtn[i],&QPushButton::clicked,[=](){
//            QString str=QString("你当前点击的是第%1个按钮").arg(i+1);
//            qDebug()<<str;

            plays[i] =new PlayScene(i+1);

            chooses->hide();
            plays[i]->move(chooses->x(),chooses->y());
            plays[i]->show();


            connect(plays[i],&PlayScene::isWined,[=]{
                //胜利之后就将计时器停止
                plays[i]->sttimer->stop();
                if(plays[i]->m_LevelNum<20)
                {
                    chooses->levcfg.setLevelLock(plays[i]->m_LevelNum,true);
                    //闯过一关，就将下一关解锁,注意关卡是从1开始的，数组是从0开始
                    //最少从第二关开始解锁,防止被多次解锁(释放)
                    if(chooses->labelLock[plays[i]->m_LevelNum]!=NULL)
                    {

                        delete chooses->labelLock[plays[i]->m_LevelNum];
                        chooses->labelLock[plays[i]->m_LevelNum]=NULL;
                    }
                }

                levelLockPrint();
            });

            //如果三个窗口任意一个关闭，都会导致文件更新
            connect(mains,&MainScene::closeAndSave,&chooses->levcfg,[=](){chooses->levcfg.saveFile();});
            connect(chooses,&ChooseLevelScene::closeAndSave,&chooses->levcfg,[=](){chooses->levcfg.saveFile();});
            connect(plays[i],&PlayScene::closeAndSave,&chooses->levcfg,[=](){chooses->levcfg.saveFile();});

            //游戏场景===>选择关卡场景
            connect(plays[i]->retbtn,&QPushButton::clicked,[=](){
                plays[i]->retbtn->zoom1();
                plays[i]->retbtn->zoom2();
                QTimer::singleShot(500,this,[=](){
                    chooses->move(plays[i]->x(),plays[i]->y());
                    delete plays[i];
                    plays[i]=NULL;
                    chooses->show();
                });
            });
         });
    }
//    //游戏场景=====>下一关
//    for(int i=0;i<N;i++)
//    {
//        connect(plays[i]->nextlev,&MyPushButton::clicked,[=](){

//            int levnum=nowLevelNum();
//            if(i<levnum-1)
//            {
//                plays[i]->nextlev->zoom1();
//                plays[i]->nextlev->zoom2();
//                QTimer::singleShot(500,this,[=](){
//                    delete plays[i];
//                    plays[i]=NULL;
//                });



//                plays[i] =new PlayScene(i+1+1);

//                //chooses->hide();
//                plays[i]->move(chooses->x(),chooses->y());
//                plays[i]->show();

//                connect(plays[i],&PlayScene::isWined,[=]{
//                    chooses->levcfg.levelLock[plays[i]->m_LevelNum]=true;
//                    //闯过一关，就将下一关解锁,注意关卡是从1开始的，数组是从0开始
//                    //最少从第二关开始解锁,防止被多次解锁(释放)
//                    if(chooses->labelLock[plays[i]->m_LevelNum]!=NULL)
//                    {

//                        delete chooses->labelLock[plays[i]->m_LevelNum];
//                        chooses->labelLock[plays[i]->m_LevelNum]=NULL;
//                    }

//                    //levelLockPrint();
//                });

//                //如果三个窗口任意一个关闭，都会导致文件更新
//                connect(mains,&MainScene::closeAndSave,[=](){chooses->levcfg.saveFile();});
//                connect(chooses,&ChooseLevelScene::closeAndSave,[=](){chooses->levcfg.saveFile();});
//                connect(plays[i],&PlayScene::closeAndSave,[=](){chooses->levcfg.saveFile();});

//                //游戏场景===>选择关卡场景
//                connect(plays[i]->retbtn,&QPushButton::clicked,[=](){
//                    plays[i]->retbtn->zoom1();
//                    plays[i]->retbtn->zoom2();
//                    QTimer::singleShot(500,this,[=](){
//                        chooses->move(plays[i]->x(),plays[i]->y());
//                        delete plays[i];
//                        plays[i]=NULL;
//                        chooses->show();
//                    });
//                });
//            }

//        });
//    }



    //游戏场景=====>上一关

    //游戏场景=====>重置本关

}
int SceneManager::nowLevelNum()
{

    for(int i=0;i<N;i++)
    {
        if(chooses->levcfg.getLevelLock(i)!=true)
        {
            return i;

        }
    }
    return N;
}

SceneManager::~SceneManager()
{
    delete mains;
    mains=NULL;
    delete chooses;
    chooses=NULL;

}
void SceneManager::levelLockPrint()
{
    for(int i=0;i<20;i++)
    {
        cout<<chooses->levcfg.getLevelLock(i)<<" ";

    }
    cout.flush();
}
