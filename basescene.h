#ifndef BASESCENE_H
#define BASESCENE_H

#include <QMainWindow>
#include<QCloseEvent>
class BaseScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit BaseScene(QWidget *parent = nullptr);



signals:

};

#endif // BASESCENE_H
