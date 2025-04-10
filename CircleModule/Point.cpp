#include "Point.h"

Point::Point(int x_, int y_) {
    this->x = x_;
    this->y = y_;
}

void Point::setX(int _x) {
    this->x = _x;
}

int Point::getX() const {
    return this->x;
}

void Point::setY(int _y) {
    this->y = _y;
}

int Point::getY() const {
    return this->y;
}