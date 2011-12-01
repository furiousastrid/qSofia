#pragma once

#include <QtGui/QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

protected slots:
    void addSheep1();
    void addSheep2();
    void addSheep3();
    void addSheep4();
    void killSheep(bool mode);

private:
    QGraphicsScene *scene;
    QAction *buttonKill;
};
