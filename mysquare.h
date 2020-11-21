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
    // Методы не определны и строго указываем что у этих методов нет реализации
    // и все кто отнаследовались обязаны реализовать эти методы сами
    virtual QRectF boundingRect() const = 0; // отрисовывает матрицу для манипуляции с объектами
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0; // отрисовка фигур
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) = 0; // триггер двойоного нажатия мыши
    virtual bool ThisAlloc() = 0; // возвращает "выделены или круг"
    virtual void setBrush(QBrush brush) = 0; // установить кисть

    void mousePressEvent(QGraphicsSceneMouseEvent *event); // проверка нажатия кнопки мыши
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event); // проверка отжатия кнопки мыши

protected slots:
    QPen TempPen(); // обводка для выделенных фигур
    QBrush AllocSquare(); // заливка для выделенных фигур
};

class CCircle : public MySquare { // класс Круга
private:
    QRectF rect_; // фигура
    QBrush brush_; // кисть
    QPen pen_; // ручка обводки
    QPainter *painter; // метод отрисовки
    bool isAlloc = false; // выделен ли?
public:
    CCircle() : MySquare() {

    }
    CCircle(QRectF Rect, QPen Pen, QBrush Brush) : MySquare(){
        this->rect_ = Rect;
        this->pen_  = Pen;
        this->brush_ = Brush;
    }
    // отнаследованные методы, описаны в суперклассе
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void setBrush(QBrush brush) override;

    bool ThisAlloc() override;
};

class CRect : public MySquare { // класс Прямоугольника
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
    // отнаследованные методы, описаны в суперклассе
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    void setBrush(QBrush brush) override;

    bool ThisAlloc() override;
};

#endif // MYSQUARE_H
