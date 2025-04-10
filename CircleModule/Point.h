#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x;
    int y;

public:
    Point(int x_, int y_); // 构造函数声明
    void setX(int _x);     // 设置 x
    int getX() const;      // 获取 x
    void setY(int _y);     // 设置 y
    int getY() const;      // 获取 y
};

#endif // POINT_H