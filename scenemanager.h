#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <QObject>

#include"mainscene.h"
#include"chooselevelscene.h"
#include"playscene.h"
class SceneManager : public QObject
{
    Q_OBJECT
public:
    explicit SceneManager(QObject *parent = nullptr);
    virtual ~SceneManager();
    int nowLevelNum();

    void levelLockPrint();

signals:

private:
    MainScene *mains=NULL;
    ChooseLevelScene *chooses=NULL;
    PlayScene *plays[N]={NULL};


};

#endif // SCENEMANAGER_H
