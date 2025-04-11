#include <iostream>
using namespace std;

void myPrint(int a, int b) {
    cout << "��ͨ����: a = " << a << ", b = " << b << endl;
}

template<typename T>
void myPrint(T a, T b) {
    cout << "ģ�庯��: a = " << a << ", b = " << b << endl;
}

template<typename T>
void myPrint(T a, T b, T c) {
    cout << "ģ������: a = " << a << ", b = " << b << ", c = " << c << endl;
}

template<typename T>
void myPrint(T a, double b) {
    cout << "ģ�����ƥ��: a = " << a << ", b = " << b << endl;
}

void test01() {
    int a = 1, b = 2, c = 3;
    // ������ͨ����
    myPrint(a, b);
    // ǿ��ģ��
    myPrint<>(a, b);
    // ģ������
    myPrint(a, b, c);
    // ���ƥ��
    myPrint(a, 2.5);
}

int main() {
    test01();
    return 0;
}
/* ���:
��ͨ����: a = 1, b = 2
ģ�庯��: a = 1, b = 2
ģ������: a = 1, b = 2, c = 3
ģ�����ƥ��: a = 1, b = 2.5
*/