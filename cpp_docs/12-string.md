# 1. String 基本概念

## 1.1 定义

+ 本质：`string` 是 C++ 标准库中的类，封装了对字符串的管理。
+ 头文件：`<string>`。

## 1.2 与 `char*` 的区别

+ `char*`：C 风格字符串，仅为指向字符数组的指针，需手动管理内存。
+ `string`：C++ 类，内部封装 `char*`，提供丰富的操作接口，自动管理内存。

## 1.3 特点

+ **功能丰富**：内置方法支持拷贝、查找、替换、插入、删除等操作。
+ **内存安全**：自动处理内存分配和释放，避免越界等问题。
+ **易用性**：提供简洁的接口，简化字符串操作。

# 2. String 的构造函数

## 2.1 函数原型

+ `string();` 默认构造，创建空字符串。
+ `string(const char* s);` 用 C 风格字符串初始化。
+ `string(const string& str);` 拷贝构造，用另一 string 对象初始化。
+ `string(int n, char c);` 用 n 个字符 c 初始化。

## 2.2 示例代码

```c++
#include <iostream>
#include <string>
using namespace std;

void test01() {
    string s1;                  // 空字符串
    cout << "s1 = \"" << s1 << "\"" << endl;

    string s2("hello");         // C 风格字符串初始化
    cout << "s2 = " << s2 << endl;

    string s3(s2);              // 拷贝构造
    cout << "s3 = " << s3 << endl;

    string s4(5, 'x');          // 5 个 'x'
    cout << "s4 = " << s4 << endl;
}

int main() {
    test01();
    return 0;
}
/* 输出:
s1 = ""
s2 = hello
s3 = hello
s4 = xxxxx
*/
```

# 3. 常用的 API 函数

## 3.1 `assign()`：将一个字符串的内容赋给当前字符串，可以是另一个字符串或指定的字符数组。

```c++
string str;
str.assign("Hello, world!");
cout << str << endl;  // 输出：Hello, world!
```

## 3.2 `copy()`：将字符串的一部分复制到字符数组中，返回复制的字符数。

```c++
string str = "Hello, world!";
char buffer[6];
str.copy(buffer, 5, 0);  // 从位置 0 开始复制 5 个字符
buffer[5] = '\0';  // 添加终止符
cout << buffer << endl;  // 输出：Hello
```

## 3.3 `begin()`：返回指向字符串首字符的迭代器。rbegin()：反向

```c++
string str = "Hello";
cout << *str.begin() << endl;  // 输出：H
```

## 3.4 `end()`：返回指向字符串末尾后一个位置的迭代器。rend()：反向

```c++
string str = "Hello";
cout << *(str.end() - 1) << endl;  // 输出：o
```

## 3.5 `size()`：返回字符串的长度（即字符数）。`length()` 与 `size()` 等价。

```c++
string name = "Jack";
cout << name.size() << endl;  // 输出：4
cout << name.length() << endl;  // 输出：4
```

## 3.6 `max_size()`：返回字符串能够容纳的最大字符数。

```c++
string str;
cout << str.max_size() << endl;  // 输出字符串的最大大小（平台相关）
```

## 3.7 `capacity()`：返回当前分配的内存容量（即，当前 string 可以容纳的字符数，而不需要重新分配内存）

```c++
string str = "Hello";
cout << str.capacity() << endl;  // 输出：15（可能因实现不同而变化）
```

## 3.8 `reserve()`：为字符串预留指定数量的内存空间，避免多次重新分配。

```c++
string str = "Hello";
str.reserve(100);  // 为字符串预留至少 100 个字符的内存
cout << str.capacity() << endl;  // 输出：100
```

## 3.9 `swap()`：交换两个字符串的内容。

```c++
string str1 = "Hello";
string str2 = "World";
str1.swap(str2);
cout << str1 << " " << str2 << endl;  // 输出：World Hello
```

## 3.10 `insert()`：在指定位置插入一个字符或字符串。

```c++
string str = "Hello!";
str.insert(5, " beautiful");
cout << str << endl;  // 输出：Hello beautiful!
```

## 3.11 `append()`：向字符串末尾追加字符或字符串。

```c++
string str = "Hello";
str.append(", World!");
cout << str << endl;  // 输出：Hello, World!
```

## 3.12 `push_back()`：在字符串末尾添加单个字符。

```c++
string str = "Hell";
str.push_back('o');
cout << str << endl;  // 输出：Hello
```

## 3.13 `erase()`：删除字符串中的一部分字符。

```c++
string str = "Hello, world!";
str.erase(5, 7);  // 从位置 5 开始删除 7 个字符
cout << str << endl;  // 输出：Hello
```

## 3.14 `clear()`：清空字符串的内容。

```c++
string str = "Hello";
str.clear();
cout << (str.empty() ? "Empty" : "Not Empty") << endl;  // 输出：Empty
```

## 3.15 `resize()`：调整字符串的大小，增加或减少字符数。

```c++
string name = "jack";
cout << "name = [" << name << "]" << endl;
cout << "name.size() = " << name.size() << endl;
cout << "name.capacity() = " << name.capacity() << endl;
cout << endl;

name.resize(10);
cout << "name = [" << name << "]" << endl;
cout << "name.size() = " << name.size() << endl;
cout << "name.capacity() = " << name.capacity() << endl;
cout << endl;

// name = [jack]
// name.size() = 4
// name.capacity() = 15
// 
// name = [jack      ]
// name.size() = 10
// name.capacity() = 15
```

## 3.16 `replace()`：替换字符串中的一部分内容。

```c++
string str = "Hello, world!";
str.replace(7, 5, "C++");
cout << str << endl;  // 输出：Hello, C++!
```

## 3.17 `find()`：返回指定子字符串首次出现的位置。

```c++
string str = "Hello, world!";
size_t pos = str.find("world");
cout << "Found at position: " << pos << endl;  // 输出：7
```

## 3.18 `substr()`：返回字符串的子字符串。

```c++
string str = "Hello, world!";
string sub = str.substr(7, 5);  // 从位置 7 开始，获取 5 个字符
cout << sub << endl;  // 输出：world
```

## 3.19 `compare()`：比较当前字符串与另一个字符串，如果相等返回 0，若当前字符串小于另一个字符串返回负数，若大于返回正数。

```c++
string str1 = "Hello";
string str2 = "World";
int result = str1.compare(str2);
cout << result << endl;  // 输出：负数（表示 str1 小于 str2）
```
