#include <QApplication>
#include<scenemanager.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SceneManager sm;

    return a.exec();
}
