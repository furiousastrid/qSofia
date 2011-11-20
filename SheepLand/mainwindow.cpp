#include "mainwindow.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QToolBar>

MainWindow::MainWindow()
{
    QGraphicsView *view = new QGraphicsView(scene);

    setCentralWidget(view);
    view->show();
    //scene->setBackgroundBrush(Qt::green);
    //QToolBar *toolBar = addToolBar(tr("Menu"));
    //toolBar->addAction("sheep");
    //toolBar->setAllowedAreas(Qt::BottomToolBarArea);
    //toolBar->setMovable(false);
}

MainWindow::~MainWindow()
{
}
