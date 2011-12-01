#pragma once

#include <QGraphicsObject>

class MyItem : public QGraphicsObject
{
    Q_OBJECT

public:
    MyItem(QPixmap& pixmap, bool mode);
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* styleGraphicsItem, QWidget* widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void setKillingMode(bool mode);

private:
    QGraphicsPixmapItem *pixmapItem;
    bool killingMode;
};
