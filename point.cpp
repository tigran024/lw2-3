#include "point.h"
#include <QPainter>

Point::Point(int x, int y, int w)
{
    this->x=x;
    this->y=y;
    this->w=w;
}

int Point::getX()
{
    return x;
}

void Point::setX(int newX)
{
    x = newX;
}

int Point::getY()
{
    return y;
}

void Point::setY(int newY)
{
    y = newY;
}

int Point::getW()
{
    return w;
}

void Point::setW(int newW)
{
    w = newW;
}

void Point::draw(QPainter *painter)
{
    QPen pen(Qt::black);
    (getW()<8) ? pen.setWidth(1) : pen.setWidth(2);
    painter->setPen(pen);
    painter->drawLine(getX(),getY()-getW(), getX(),getY()+getW());
    painter->drawLine(getX()-getW(),getY(), getX()+getW(),getY());
}
