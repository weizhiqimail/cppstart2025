#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h" // ���� Point ��
#include "Color.h" // ���� Color ��

class Circle {
private:
    int radius = 0;
    Point point;
    Color color;

public:
    Circle(int r, int x, int y, Color c = Color(0, 0, 0)); // ���캯�� 1
    Circle(int r, Point p, Color c = Color(0, 0, 0));      // ���캯�� 2
    void setRadius(int r);                                 // ���ð뾶
    int getRadius() const;                                 // ��ȡ�뾶
    void setPointer(Point point);                          // ����Բ��
    void calcArea();                                       // �������
    Point getPointer() const;                              // ��ȡԲ��
    void setColor(Color c);                                // ������ɫ
    void printInfo() const;                                // ��ӡ��Ϣ
};

#endif // CIRCLE_H