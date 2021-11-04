#include "levelconfig.h"
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<QTextCodec>
#include<QThread>
LevelConfig::LevelConfig(QObject *parent) : QObject(parent)
{
    initLevel();



}
void LevelConfig::initLevel()
{
     levelLock[0]=true;
     for(int i=1;i<20;i++)
     {

         levelLock[i]=false;
     }

}
void LevelConfig::openFile()
{

    initLevel();
    //加载文件
    QFile file(LEVELDATA_FILE);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        qDebug()<<"打开失败，文件不存在";
        hasSaveFile=false;
        return;
    }

    QTextStream in(&file);
    //不管是写问价还是读文件之前都可一将它设置为UTF-8格式作为标准
    in.setCodec("UTF-8");
    while(!in.atEnd())
    {
        QString line=in.readLine();

        QStringList list= line.split(" ");
        QString n = list.at(0);
        QString v = list[1];
        levelLock[n.toInt()]=v.toInt();

    }


    file.close();
    emit openResultReady("hello");


}
void LevelConfig::saveFile()
{

    QFile file(LEVELDATA_FILE);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text))
    {
        qDebug()<<"存档失败";
        return;
    }
    QTextStream out(&file);
    out.setCodec("UTF-8");
    for(int i=0;i<20;i++)
    {
        QString str=QString::number(i)+
                    QString(" ")+
                    QString::number(levelLock[i]?1:0);
        out<<str<<"\n";
    }
    file.close();
    qDebug() << "I'm working in threadsave:" << QThread::currentThreadId();
}

void LevelConfig::setLevelLock(int num,bool val)
{
    levelLock[num]=val;
}
bool LevelConfig::getLevelLock(int num)
{
    return levelLock[num];
}
