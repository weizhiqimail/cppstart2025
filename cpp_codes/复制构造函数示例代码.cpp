#include <iostream>
#include <cstring>

using namespace std;

class Point {
private:
    int x;
    int y;

public:
    Point(int x_, int y_) {
        this->x = x_;
        this->y = y_;
    }

    void setX(int _x) {
        this->x = _x;
    }

    int getX() const {
        return this->x;
    }

    void setY(int _y) {
        this->y = _y;
    }

    int getY() const {
        return this->y;
    }
};

class Circle {
private:
    int radius = 0;
    Point point;

public:
    Circle(int r, Point p) : radius(r),point(p) {
        cout << "Circle ���캯����int r, Point p" << endl;
    }

    Circle(Circle &circle): radius(circle.radius), point(circle.point) {
        cout << "Circle ���ƹ��캯��" << endl;
    }

    void setRadius(int r) {
        this->radius = r;
    }

    int getRadius() const {
        return this->radius;
    }

    void setPointer(Point point) {
        this->point = point;
    }

    void setPointer(int x, int y) {
        this->point = Point(x, y);
    }

    void calcArea() {
        double area = 3.14 * this->radius * this->radius;
        cout << "Բ�����: " << area << endl;
    }

    Point getPointer() const {
        return this->point;
    }


    void printInfo(string prefix  = "") const {
        Point point = this->point;
        if (strlen(prefix.c_str()) > 0) {
            cout << prefix << endl;
        }
        cout << "Circle ��Ϣ" << endl;
        cout << "�뾶: " << this->radius << endl;
        cout << "Բ������: (" << point.getX() << ", " << point.getY() << ")" << endl;
        cout << endl;
    }
};

int main() {
    // ��ʼ��һ�� Point ����
    Point point = Point(8, 8);
    // ��ʼ��һ�� Circle ����
    Circle circle1 = Circle(8, point);
    circle1.printInfo("circle 1 �Ļ�����Ϣ");

    Circle circle2 = circle1;   // ʹ��Ĭ�ϵĸ��ƹ��캯��������ǳ����
    circle2.printInfo("circle 2 �Ļ�����Ϣ");

    cout << "-------------------------" << endl;

    // �޸� circle1 �����ԣ�circle2 �����Բ��ᷢ���仯
    circle1.setRadius(18);
    circle1.setPointer(18, 18);
    circle1.printInfo("circle1.setRadius(18) ---- circle 1 �Ļ�����Ϣ");
    circle2.printInfo("circle1.setRadius(18) ---- circle 2 �Ļ�����Ϣ");

    // �޸� circle2 �����ԣ�circle1 ������Ҳ���ᷢ���仯
    circle2.setRadius(28);
    circle2.setPointer(28, 28);
    circle1.printInfo("circle2.setRadius(28) ---- circle 1 �Ļ�����Ϣ");
    circle2.printInfo("circle2.setRadius(28) ---- circle 2 �Ļ�����Ϣ");

    return 0;
};
