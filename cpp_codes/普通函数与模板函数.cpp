#include <iostream>
using namespace std;

void myPrint(int a, int b) {
    cout << "普通函数: a = " << a << ", b = " << b << endl;
}

template<typename T>
void myPrint(T a, T b) {
    cout << "模板函数: a = " << a << ", b = " << b << endl;
}

template<typename T>
void myPrint(T a, T b, T c) {
    cout << "模板重载: a = " << a << ", b = " << b << ", c = " << c << endl;
}

template<typename T>
void myPrint(T a, double b) {
    cout << "模板最佳匹配: a = " << a << ", b = " << b << endl;
}

void test01() {
    int a = 1, b = 2, c = 3;
    // 优先普通函数
    myPrint(a, b);
    // 强制模板
    myPrint<>(a, b);
    // 模板重载
    myPrint(a, b, c);
    // 最佳匹配
    myPrint(a, 2.5);
}

int main() {
    test01();
    return 0;
}
/* 输出:
普通函数: a = 1, b = 2
模板函数: a = 1, b = 2
模板重载: a = 1, b = 2, c = 3
模板最佳匹配: a = 1, b = 2.5
*/