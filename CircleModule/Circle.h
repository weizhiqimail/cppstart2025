#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h" // 依赖 Point 类
#include "Color.h" // 依赖 Color 类

class Circle {
private:
    int radius = 0;
    Point point;
    Color color;

public:
    Circle(int r, int x, int y, Color c = Color(0, 0, 0)); // 构造函数 1
    Circle(int r, Point p, Color c = Color(0, 0, 0));      // 构造函数 2
    void setRadius(int r);                                 // 设置半径
    int getRadius() const;                                 // 获取半径
    void setPointer(Point point);                          // 设置圆心
    void calcArea();                                       // 计算面积
    Point getPointer() const;                              // 获取圆心
    void setColor(Color c);                                // 设置颜色
    void printInfo() const;                                // 打印信息
};

#endif // CIRCLE_H