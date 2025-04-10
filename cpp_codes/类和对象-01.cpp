#include <iostream>

using namespace std;

void testCRectangle() {

    class CRectangle {
    public:
        int w, h;

        void Init(int w_, int h_) {
            w = w_;
            h = h_;
        }

        int Area() {
            return w * h;
        }

        int Perimeter() {
            return 2 * (w + h);
        }
    };

    // 栈上创建对象：创建一个 CRectangle 对象
    CRectangle rect1{};
    rect1.Init(10, 20);
    cout << "====== rect1 ======" << endl;
    cout << "Area: " << rect1.Area() << endl;
    cout << "Perimeter: " << rect1.Perimeter() << endl;

    CRectangle *p1 = &rect1;
    cout << "====== *p1 = &rect1 ======" << endl;
    cout << "p1     = " << hex << p1 << endl;
    cout << "&rect1 = " << hex << &rect1 << endl;

    // 堆上创建对象：new 一个 CRectangle 对象
    CRectangle *rect2 = new CRectangle();
    rect2->Init(30, 40);
    cout << "====== rect2 ======" << endl;
    cout << dec;
    cout << "rect2 Area: " << rect2->Area() << endl;
    cout << "rect2 Perimeter: " << rect2->Perimeter() << endl;

    CRectangle *p2 = rect2;
    p2->Init(50, 60);
    cout << "p2 Area: " << p2->Area() << endl;
    cout << "p2 Perimeter: " << p2->Perimeter() << endl;
    cout << "====== p2 = rect2 ======" << endl;
    cout << "p2     = " << hex << p2 << endl;
    cout << "&rect2 = " << hex << &rect2 << endl;
}

int main() {
    testCRectangle();
    return 0;
}
