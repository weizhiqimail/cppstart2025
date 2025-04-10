#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(int r, int x, int y, Color c) : point(x, y), color(c) {
    this->radius = r;
}

Circle::Circle(int r, Point p, Color c) : point(p), color(c) {
    this->radius = r;
}

void Circle::setRadius(int r) {
    this->radius = r;
}

int Circle::getRadius() const {
    return this->radius;
}

void Circle::setPointer(Point point) {
    this->point = point;
}

void Circle::calcArea() {
    double area = 3.14 * this->radius * this->radius;
    cout << "圆的面积: " << area << endl;
}

Point Circle::getPointer() const {
    return this->point;
}

void Circle::setColor(Color c) {
    this->color = c;
}

void Circle::printInfo() const {
    Point point = this->point;
    Color color = this->color;

    cout << "Circle 信息" << endl;
    cout << "半径: " << this->radius << endl;
    cout << "圆心坐标: (" << point.getX() << ", " << point.getY() << ")" << endl;
    cout << "颜色: (" << color.getRed() << ", " << color.getGreen() << ", " << color.getBlue() << ")" << endl;
    cout << endl;
}