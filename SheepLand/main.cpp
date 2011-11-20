#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setBaseSize(1000, 1000);
    w.show();

    return a.exec();
}
