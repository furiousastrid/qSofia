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

private:
    QGraphicsScene *scene;
};
