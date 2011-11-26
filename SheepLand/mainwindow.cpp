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
}

void MainWindow::addSheep1()
{
    QPixmap *pixmap = new QPixmap("sheep1.png");
    MyItem *sheep1 = new MyItem(*pixmap);
    scene->addItem(sheep1);
    //sheep1->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::addSheep2()
{
    QPixmap *pixmap = new QPixmap("sheep2.png");
    QGraphicsPixmapItem *sheep2 = new QGraphicsPixmapItem(*pixmap);
    scene->addItem(sheep2);
    sheep2->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::addSheep3()
{
    QPixmap *pixmap = new QPixmap("sheep3.png");
    QGraphicsPixmapItem *sheep3 = new QGraphicsPixmapItem(*pixmap);
    scene->addItem(sheep3);
    sheep3->setFlag(QGraphicsItem::ItemIsMovable);
}

void MainWindow::addSheep4()
{
    QPixmap *pixmap = new QPixmap("sheep4.png");
    QGraphicsPixmapItem *sheep4 = new QGraphicsPixmapItem(*pixmap);
    scene->addItem(sheep4);
    sheep4->setFlag(QGraphicsItem::ItemIsMovable);
}

MainWindow::~MainWindow()
{
}
