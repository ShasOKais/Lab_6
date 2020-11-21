#include "mysquare.h"

//MySquare - mouse

//CRect - mouse
MySquare::MySquare()
{
    setFlag(ItemIsMovable);
}

void MySquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = true;
    this->setCursor(QCursor(Qt::ClosedHandCursor)); // установить курсор "сжатый кулак"
    update();
    QGraphicsItem::mousePressEvent(event);
}

void MySquare::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed = false;
    this->setCursor(QCursor(Qt::ArrowCursor)); // вернуть обычный курсор "стрелка"
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}

// All - BoundingRect()
QRectF CCircle::boundingRect() const
{
    qreal penWidth = 300;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth / 2, 20 + penWidth / 2);
}

QRectF CRect::boundingRect() const
{
    qreal penWidth = 300;
    return QRectF(-10 - penWidth / 2, -10 - penWidth / 2, 20 + penWidth / 2, 20 + penWidth / 2);
}

QPen MySquare::TempPen(){
    QPen tempPen(Qt::yellow);
    tempPen.setWidth(5);
    return tempPen;
}

QBrush MySquare::AllocSquare(){
    QBrush allocSquare(Qt::yellow, Qt::SolidPattern);
    return allocSquare;
}

void CRect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    rect_ = boundingRect(); // переприсваивание для манипуляции с объектом
    painter->setPen(this->pen_);
    painter->setBrush(this->brush_);
    if(Pressed){ // Если выбрана фигура
        painter->setBrush(AllocSquare());
    } else {
        painter->setBrush(this->brush_);
    }
    if(ThisAlloc()){ // Если выделена фигура
        painter->setPen(TempPen());
    } else {
        painter->setPen(this->pen_);
    }
    painter->drawEllipse(rect_);
    update();
}


void CRect::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    isAlloc = this->isAlloc ? false : true;
    update();
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void CRect::setBrush(QBrush brush)
{
    this->brush_ = brush;
}

bool CRect::ThisAlloc()
{
    return this->isAlloc;
}

void CCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    rect_ = boundingRect(); // переприсваивание для манипуляции с объектом
    painter->setPen(this->pen_);
    painter->setBrush(this->brush_);
    if(Pressed){
        painter->setBrush(AllocSquare());
    } else {
        painter->setBrush(this->brush_);
    }
    if(ThisAlloc()){
        painter->setPen(TempPen());
    } else {
        painter->setPen(this->pen_);
    }
    painter->drawRect(rect_);
    update();
}

void CCircle::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    isAlloc = this->isAlloc ? false : true;
    update();
    QGraphicsItem::mouseDoubleClickEvent(event);
}

void CCircle::setBrush(QBrush brush)
{
    this->brush_ = brush;
}

bool CCircle::ThisAlloc() {
    return this->isAlloc;
}
