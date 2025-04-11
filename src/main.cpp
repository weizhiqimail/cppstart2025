#include <iostream>
#include <string>
using namespace std;

class MyPrint {
public:
    void operator()(const string &name) const {
        cout << "name = " << name << endl;
    }
};

class MyAdd {
public:
    int operator()(int num1, int num2) const {
        return num1 + num2;
    }
};

void test01() {
    MyPrint myPrint;
    myPrint("Sherry");
}

void test02() {
    MyAdd myAdd;
    cout << "myAdd(1, 2) = " << myAdd(1, 2) << endl;
    cout << "匿名调用: " << MyAdd()(1, 4) << endl;
}

int main() {
    // test01();
    test02();
    return 0;
}
/* 输出:
myAdd(1, 2) = 3
匿名调用: 5
*/