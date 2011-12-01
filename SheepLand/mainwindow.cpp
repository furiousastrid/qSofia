#include "mainwindow.h"
#include "myitem.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QToolBar>
#include <QAction>

MainWindow::MainWindow()
{
    setGeometry(100, 100, 800, 500);
    setFixedSize(800, 500);
    scene = new QGraphicsScene;
    QGraphicsView *view = new QGraphicsView(scene);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->show();
    setCentralWidget(view);
    scene->setBackgroundBrush(QColor(0, 100, 0));
    QToolBar *toolBar = addToolBar(tr("Menu"));
    addToolBar(Qt::BottomToolBarArea, toolBar);
    toolBar->setMovable(false);
    QAction *button1 = toolBar->addAction("Wooly");
    connect(button1, SIGNAL(triggered()), SLOT(addSheep1()));
    QAction *button2 = toolBar->addAction("Ready");
    connect(button2, SIGNAL(triggered()), SLOT(addSheep2()));
    QAction *button3 = toolBar->addAction("Happy");
    connect(button3, SIGNAL(triggered()), SLOT(addSheep3()));
    QAction *button4 = toolBar->addAction("Golfing");
    connect(button4, SIGNAL(triggered()), SLOT(addSheep4()));
    toolBar->addSeparator();
    buttonKill = toolBar->addAction("Kill");
    buttonKill->setCheckable(true);
    connect(buttonKill, SIGNAL(toggled(bool)), SLOT(killSheep(bool)));
}

void MainWindow::addSheep1()
{
    QPixmap *pixmap = new QPixmap("sheep1.png");
    if (!buttonKill->isChecked())
    {
        MyItem *sheep1 = new MyItem(*pixmap, false);
        scene->addItem(sheep1);
    }
    else
    {
        MyItem *sheep1 = new MyItem(*pixmap, true);
        scene->addItem(sheep1);
    }
}

void MainWindow::addSheep2()
{
    QPixmap *pixmap = new QPixmap("sheep2.png");
    if (!buttonKill->isChecked())
    {
        MyItem *sheep2 = new MyItem(*pixmap, false);
        scene->addItem(sheep2);
    }
    else
    {
        MyItem *sheep2 = new MyItem(*pixmap, true);
        scene->addItem(sheep2);
    }
}

void MainWindow::addSheep3()
{
    QPixmap *pixmap = new QPixmap("sheep3.png");
    if (!buttonKill->isChecked())
    {
        MyItem *sheep3 = new MyItem(*pixmap, false);
        scene->addItem(sheep3);
    }
    else
    {
        MyItem *sheep3 = new MyItem(*pixmap, true);
        scene->addItem(sheep3);
    }
}

void MainWindow::addSheep4()
{
    QPixmap *pixmap = new QPixmap("sheep4.png");
    if (!buttonKill->isChecked())
    {
        MyItem *sheep4 = new MyItem(*pixmap, false);
        scene->addItem(sheep4);
    }
    else
    {
        MyItem *sheep4 = new MyItem(*pixmap, true);
        scene->addItem(sheep4);
    }
}

void MainWindow::killSheep(bool mode)
{
    foreach (QGraphicsItem *item, scene->items())
    {
        static_cast<MyItem*>(item)->setKillingMode(mode);
    }
}

MainWindow::~MainWindow()
{
}
