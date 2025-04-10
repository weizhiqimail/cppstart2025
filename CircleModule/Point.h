#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x;
    int y;

public:
    Point(int x_, int y_); // ���캯������
    void setX(int _x);     // ���� x
    int getX() const;      // ��ȡ x
    void setY(int _y);     // ���� y
    int getY() const;      // ��ȡ y
};

#endif // POINT_H