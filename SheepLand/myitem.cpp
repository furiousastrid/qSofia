#include "myitem.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

MyItem::MyItem(QPixmap& pixmap, bool killingMode)
{
    this->killingMode = killingMode;
    pixmapItem = new QGraphicsPixmapItem(pixmap);
    setFlag(QGraphicsItem::ItemIsMovable);
    //QRectF itemsBoundingRect = scene()->itemsBoundingRect();
    //if (intersects())
}

QRectF MyItem::boundingRect() const
{
    return pixmapItem->boundingRect();
}

void MyItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* styleGraphicsItem, QWidget* widget)
{
    pixmapItem->paint(painter, styleGraphicsItem, widget);
}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (killingMode)
    {
        setVisible(false);
        killingMode = false;
    }
}

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF startingPoint = pos();
    QGraphicsItem::mouseMoveEvent(event);
    if (!(&scene()->collidingItems(this))->isEmpty())
    {
        setPos(startingPoint);
    }
}

void MyItem::setKillingMode(bool mode)
{
    killingMode = mode;
}
