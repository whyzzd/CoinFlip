#ifndef GAMECONFIG_H
#define GAMECONFIG_H

#include <QObject>
#include<QMap>
#include<QVector>
class GameConfig : public QObject
{
    Q_OBJECT
public:
    explicit GameConfig(QObject *parent = nullptr);

    //map的第一个参数是控制关数，后面一个是嵌套的矩阵
    QMap<int,QVector<QVector <int>>>mData;

    //控制关卡是否可玩
    //bool levelLock[20]={false};
signals:

};

#endif // GAMECONFIG_H
