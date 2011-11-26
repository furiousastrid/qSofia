#include "myitem.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

MyItem::MyItem(QPixmap& pixmap)
{
    pixmapItem = new QGraphicsPixmapItem(pixmap);
    pixmapItem->setFlag(QGraphicsItem::ItemIsMovable);
}

QRectF MyItem::boundingRect() const
{
    return pixmapItem->boundingRect();
}

void MyItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* styleGraphicsItem, QWidget* widget)
{
    scene()->addItem(pixmapItem);
}

/*void QGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}*/

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF startingPoint = pos();
    if (!(&scene()->collidingItems(this))->isEmpty())
    {
        setPos(startingPoint);
    }
}

/*void QGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}*/