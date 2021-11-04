#ifndef LEVELCONFIG_H
#define LEVELCONFIG_H

#include <QObject>
#include"GlobalFile.h"
class LevelConfig : public QObject
{
    Q_OBJECT
public:
    explicit LevelConfig(QObject *parent = nullptr);



    bool hasSaveFile=true;
    void initLevel();


    void setLevelLock(int num,bool val);
    bool getLevelLock(int num);

signals:
    void openResultReady(const QString &str);


public slots:
    void openFile();
    void saveFile();

private:
    bool levelLock[20];


};

#endif // LEVELCONFIG_H
