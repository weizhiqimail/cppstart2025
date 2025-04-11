#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

template<typename T1, typename T2>
class Person {
public:
    T1 name;
    T2 age;
    Person(T1 name, T2 age) : name(name), age(age) {}
    void show() { cout << "Name: " << name << ", Age: " << age << endl; }
};

// 1. 指定类型
void printPerson1(Person<string, int> &p) {
    p.show();
}

// 2. 参数模板化
template<typename T1, typename T2>
void printPerson2(Person<T1, T2> &p) {
    p.show();
    cout << "T1 type: " << typeid(T1).name() << ", T2 type: " << typeid(T2).name() << endl;
}

// 3. 整个类模板化
template<typename T>
void printPerson3(T &p) {
    p.show();
    cout << "T type: " << typeid(T).name() << endl;
}

void test01() {
    Person<string, int> p1("Sherry", 19);
    printPerson1(p1);

    Person<string, int> p2("Tom", 20);
    printPerson2(p2);

    Person<string, int> p3("Jack", 21);
    printPerson3(p3);
}

int main() {
    test01();
    return 0;
}
/* 输出:
Name: Sherry, Age: 19
Name: Tom, Age: 20
T1 type: NSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, T2 type: i
Name: Jack, Age: 21
T type: 6PersonINSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEEiE
*/