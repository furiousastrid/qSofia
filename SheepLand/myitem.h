#pragma once

#include <QGraphicsItem>

class MyItem : public QGraphicsItem
{
public:
    MyItem(QPixmap& pixmap);
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* styleGraphicsItem, QWidget* widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    QGraphicsPixmapItem *pixmapItem;
};
