#include <iostream>
#include "./CircleModule/Circle.h"

using namespace std;

int main() {
    // 初始化 Color 对象
    Color redColor = Color(255, 0, 0);
    Circle circle1 = Circle(10, 0, 0, redColor);
    circle1.calcArea();
    circle1.printInfo();

    Color greenColor = Color(0, 255, 0);
    Point point = Point(0, 0);
    Circle circle2 = Circle(20, point, greenColor);
    circle2.calcArea();
    circle2.printInfo();

    return 0;
}
