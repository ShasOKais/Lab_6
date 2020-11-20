#ifndef MYSQUARE_H
#define MYSQUARE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QMouseEvent>
#include <QCursor>
#include <QGraphicsSceneMouseEvent>

class MySquare : public QGraphicsItem
{
public:
    MySquare();

    bool Pressed = false;

    virtual QRectF boundingRect() const = 0;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0; // отрисовка фигур
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    virtual bool ThisAlloc() = 0;
    virtual void setBrush(QBrush brush) = 0;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

protected slots:
    QPen TempPen();
    QBrush AllocSquare();
};

class CCircle : public MySquare {
private:
    QRectF rect_;
    QBrush brush_;
    QPen pen_;
    QPainter *painter;
    bool isAlloc = false;
public:
    CCircle() : MySquare() {

    }
    CCircle(QRectF Rect, QPen Pen, QBrush Brush) : MySquare(){
        this->rect_ = Rect;
        this->pen_  = Pen;
        this->brush_ = Brush;
    }

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void setBrush(QBrush brush) override;

    bool ThisAlloc() override;
};

class CRect : public MySquare {
private:
    QRectF rect_;
    QBrush brush_;
    QPen pen_;
    QPainter *painter;
    bool isAlloc = false;
public:
    CRect() : MySquare(){
        // по приколу, и чтобы не ругался компилятор
        // но в основном из за наследования
    }
    CRect(QRectF Rect, QPen Pen, QBrush Brush) : MySquare(){
        this->rect_= Rect;
        this->pen_ = Pen;
        this->brush_ = Brush;
    }

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void setBrush(QBrush brush) override;

    bool ThisAlloc() override;
};

#endif // MYSQUARE_H
