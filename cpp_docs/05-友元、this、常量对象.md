# 1. 友元

## 1.1 友元定义

+ **友元（friend）** 是一种特殊的访问控制机制，它允许某些函数或者类能够访问类的私有成员（`private`）和保护成员（`protected`），即使这些成员对于其他外部代码是不可访问的。
+ 通过友元，特定的函数或类能够**绕过类的封装性，直接操作类的内部数据**。
+ **友元的基本概念**
  + **友元函数（Friend Function）**：一个非成员函数，它被声明为某个类的友元函数，可以访问该类的私有成员和保护成员。 
  + **友元类（Friend Class**）：一个类被声明为另一个类的友元类，它可以访问另一个类的私有成员和保护成员。 
  + **友元成员函数（Friend Member Function）**：某个类的成员函数被声明为友元函数，可以访问该类的私有成员。
+ **友元的使用场景**
  + 当你需要在不属于某个类的其他类或函数中访问类的私有成员时，可以使用友元。 
  + 当你实现操作符重载（例如，重载 `<<` 或 `>>` 流操作符）时，友元函数常用于访问类的私有数据。
+ **特点**
  + **单向性**：友元关系是单向的，即如果类 A 允许类 B 访问其私有成员，并不意味着类 B 可以将类 A 作为它的友元，反之亦然。 
  + **不继承性**：友元关系不随类的继承而传递，即子类并不自动成为父类的友元，除非显式声明。 
  + **不具备成员身份**：友元函数和友元类并不是类的成员，它们只是获得了特定的访问权限。

## 1.2 友元函数示例

```c++
class A {
private:
    int x;

public:
    A() : x(10) {}  // 构造函数，初始化 x 为 10

    // 声明 B 为 A 的友元类
    friend class B;

    // 声明友元函数
    friend void displayA(const A& a);
};

// 友元函数，可以访问 A 的私有成员
void displayA(const A& a) {
    cout << "A's private member x: " << a.x << endl;
}

// 友元类 B，可以访问 A 的私有成员
class B {
public:
    void showA(const A& a) {
        // B 可以访问 A 的私有成员 x
        cout << "B accessing A's private member x: " << a.x << endl;
    }
};

int main() {
    A a;
    displayA(a);  // 友元函数访问 A 的私有成员

    B b;
    b.showA(a);   // 友元类 B 访问 A 的私有成员

    return 0;
}
/**
A's private member x: 10
B accessing A's private member x: 10
 */
```

# 2. `this` 指针

## 2.1 `this` 指针定义

+ `this` 指针是一个特殊的指针，它指向当前对象的地址。
+ `this` 指针是每个非静态成员函数隐式提供的，指向调用该成员函数的对象。
+ 可以通过 `this` 指针访问当前对象的成员变量和成员函数。
+ `this` 指针的类型是 `T*`，其中 `T` 是类的类型。

## 2.1 从 C++ 程序到 C 程序的翻译

+ C++ 程序

```c++
class CCar {
public:
    int price;

    void SetPrice(int p);
};

void CCar::SetPrice(int p) {
    price = p;
}

int main() {
    CCar car;
    car.SetPrice(20000);
    return 0;
}
```

+ 编译成C语言

```c++
struct CCar {
    int price;
};

void SetPrice(struct CCar *this, int p) {
    this->price = p;
}

int main() {
    struct CCar car;
    SetPrice(& car, 20000);
    return 0;
}
```

# 3. 常量对象、常量成员函数和常量引用

## 3.1 常量对象

+ 用 `const` 定义的对象，其成员变量不可修改。

```c++
class Demo {
private:
    int value;
public:
    void SetValue() {}
};

const Demo obj;  // 常量对象
```

## 3.2 常量成员函数

+ 在函数声明后加 `const`，表示函数不会修改对象。
+ 不能修改非静态成员变量，也不能调用非静态非常量成员函数。

```c++
#include <iostream>
using namespace std;

class Sample {
public:
    int value;
    void GetValue() const {
        // value = 0;  // 错误
        cout << value << endl;
    }
    void func() {}
};

int main() {
    const Sample o;
    o.GetValue();  // 合法
    // o.func();   // 错误
    return 0;
}
```

## 3.3 常量成员函数的重载

+ 同名函数，一个加 `const` 一个不加，构成重载。

```c++
#include <iostream>
using namespace std;

class CTest {
private:
    int n;
public:
    CTest() { n = 1; }
    int GetValue() const { return n; }
    int GetValue() { return 2 * n; }
};

int main() {
    const CTest obj1;
    CTest obj2;
    cout << obj1.GetValue() << "," << obj2.GetValue() << endl;
    return 0;
}
/* 输出:
1,2
*/
```

## 3.4 常引用

+ 用 `const` 修饰引用，不能通过该引用修改变量。
+ 常引用作为参数可避免拷贝开销并防止修改。

```c++
#include <iostream>
using namespace std;

class Sample {};

void PrintObj(const Sample &o) {}

int main() {
    Sample s;
    PrintObj(s);
    return 0;
}
```
