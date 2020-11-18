#ifndef MYSQUARE_H
#define MYSQUARE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QMouseEvent>

class MySquare : public QGraphicsItem
{
public:
    MySquare();

    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool Pressed;
    
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    //void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};

class CShape : public MySquare {
protected:
    QRect rect_;
    QPen pen_;
    QBrush brush_;
    QPainter *painter;
public:
    CShape() : MySquare(){}
    CShape(QRect Rect, QPen Pen, QBrush Brush) : MySquare(){
        this->rect_ = Rect;
        this->pen_ = Pen;
        this->brush_ = Brush;
    }
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    virtual ~CShape();
};

#endif // MYSQUARE_H
