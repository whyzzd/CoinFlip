#ifndef HELP_H
#define HELP_H

#include <QWidget>
#include<QPaintEvent>
class Help : public QWidget
{
    Q_OBJECT
public:
    explicit Help(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

signals:

};

#endif // HELP_H
