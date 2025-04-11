#include <iostream>
#include <string.h>

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
    Circle(int r, Point p) : point(p) {
        this->radius = r;
        cout << "Circle 构造函数" << endl;
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

    void calcArea() {
        double area = 3.14 * this->radius * this->radius;
        cout << "圆的面积: " << area << endl;
    }

    Point getPointer() const {
        return this->point;
    }


    void printInfo(string prefix  = "") const {
        Point point = this->point;
        if (strlen(prefix.c_str()) > 0) {
            cout << prefix << endl;
        }
        cout << "Circle 信息" << endl;
        cout << "半径: " << this->radius << endl;
        cout << "圆心坐标: (" << point.getX() << ", " << point.getY() << ")" << endl;
        cout << endl;
    }
};

class CopyCircle {
private:
    int radius = 0;
    Point point;

    CopyCircle(int r, Point p) : point(p) {
        this->radius = r;
        cout << "Circle 构造函数" << endl;
    }

    CopyCircle(const CopyCircle &copyCircle): point(copyCircle.point) {
        cout << "Circle 复制构造函数" << endl;
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

    void calcArea() {
        double area = 3.14 * this->radius * this->radius;
        cout << "圆的面积: " << area << endl;
    }

    Point getPointer() const {
        return this->point;
    }


    void printInfo() const {
        Point point = this->point;

        cout << "Circle 信息" << endl;
        cout << "半径: " << this->radius << endl;
        cout << "圆心坐标: (" << point.getX() << ", " << point.getY() << ")" << endl;
        cout << endl;
    }
};


int main() {
    // 初始化一个 Point 对象
    Point point = Point(0, 0);
    // 初始化一个 Circle 对象
    Circle circle1 = Circle(10, point);
    circle1.printInfo("circle 1 的基本信息");





    return 0;
};
