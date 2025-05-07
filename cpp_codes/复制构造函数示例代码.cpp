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
        cout << "Circle 构造函数：int r, Point p" << endl;
    }

    Circle(Circle &circle): radius(circle.radius), point(circle.point) {
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

    void setPointer(int x, int y) {
        this->point = Point(x, y);
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

int main() {
    // 初始化一个 Point 对象
    Point point = Point(8, 8);
    // 初始化一个 Circle 对象
    Circle circle1 = Circle(8, point);
    circle1.printInfo("circle 1 的基本信息");

    Circle circle2 = circle1;   // 使用默认的复制构造函数，进行浅拷贝
    circle2.printInfo("circle 2 的基本信息");

    cout << "-------------------------" << endl;

    // 修改 circle1 的属性，circle2 的属性不会发生变化
    circle1.setRadius(18);
    circle1.setPointer(18, 18);
    circle1.printInfo("circle1.setRadius(18) ---- circle 1 的基本信息");
    circle2.printInfo("circle1.setRadius(18) ---- circle 2 的基本信息");

    // 修改 circle2 的属性，circle1 的属性也不会发生变化
    circle2.setRadius(28);
    circle2.setPointer(28, 28);
    circle1.printInfo("circle2.setRadius(28) ---- circle 1 的基本信息");
    circle2.printInfo("circle2.setRadius(28) ---- circle 2 的基本信息");

    return 0;
};
