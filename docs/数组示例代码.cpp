#include <bitset>   // 包含位集头文件
#include <stdio.h> // 包含标准输入输出头文件
#include <iostream> // 包含输入输出流头文件

using namespace std; // 使用标准命名空间

template<size_t N>
string formatBitset(const bitset<N> &b) {
    string raw = b.to_string();
    string formatted;
    for (size_t i = 0; i < raw.size(); ++i) {
        formatted += raw[i];
        if ((i + 1) % 4 == 0 && i != raw.size() - 1)
            formatted += ' ';
    }
    return formatted;
}

// 封装输出一维数组的函数，增加可选参数 showAddress
template<typename T, size_t N>
void printArray(const string &arrName, T (&arr)[N], bool showAddress = false) {
    cout << "===== 一维数组元素 (" << arrName << ") 输出 =====\n";
    for (size_t i = 0; i < N; i++) {
        cout << arrName << "[" << i << "] = " << arr[i];
        if (showAddress) {
            // 将指针转换为整数类型 uintptr_t
            uintptr_t addr = reinterpret_cast<uintptr_t>(&arr[i]);
            cout << "\t(" << &arr[i] << ")";           // 输出地址
            cout << "\t" << formatBitset(bitset<32>(addr)); // 输出地址的 32 位二进制
        }
        cout << "\n";
    }
    cout << "\n";
}

// 封装输出二维数组的函数，增加可选参数 showAddress
template<typename T, size_t Rows, size_t Cols>
void print2DArray(const string &arrName, T (&arr)[Rows][Cols], bool showAddress = false) {
    cout << "===== 二维数组元素 (" << arrName << ") 输出 =====\n";
    for (size_t i = 0; i < Rows; i++) {
        for (size_t j = 0; j < Cols; j++) {
            cout << arrName << "[" << i << "][" << j << "] = " << arr[i][j];
            if (showAddress) {
                // 将指针转换为整数类型 uintptr_t
                uintptr_t addr = reinterpret_cast<uintptr_t>(&arr[i][j]);
                cout << "\t(" << &arr[i][j] << ")";         // 输出地址
                cout << "\t" << formatBitset(bitset<32>(addr)); // 输出地址的 32 位二进制
            }
            cout << "\n";
        }
    }
    cout << "\n";
}

void printText(const string &arrName) {
    cout << "===== " << arrName << " =====" << endl;
}


int main() {
    // 初始化一维数组，所有元素为 0
    // 只指定第一个元素为 0，其余元素自动填充为 0
    int c[10] = {1};
    printText("初始化一维数组 c[10]，所有元素为 0；只指定第一个元素为 1，其余元素自动填充为 0");
    printArray("c", c, true);
    cout << "c: " <<c << endl;
    cout << "&c:" << &c << endl;

    // 初始化二维数组，所有元素为 0
    // 使用嵌套初始化列表显式指定每个元素
    int c1[3][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    printText("初始化二维数组 c1[3][4]，所有元素为 0；使用嵌套初始化列表显式指定每个元素");
    print2DArray("c1", c1, true);

    // 初始化二维数组，仅提供部分元素
    // {1, 2, 3, 4} 会按行填充 c2[0][0] 到 c2[0][3]，其余元素自动为 0
    int c2[3][4] = {1, 2, 3, 4};
    printText("初始化二维数组 c2[3][4]，仅提供部分元素；{1, 2, 3, 4} 会按行填充 c2[0][0] 到 c2[0][3]，其余元素自动为 0");
    print2DArray("c2", c2, true);

    // 初始化一维数组，编译器根据初始化列表推断大小为 10
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printText("初始化一维数组 a[]，编译器根据初始化列表推断大小为 10");
    // 打印数组 a 的首地址，%p 需要 void* 类型指针
    printf("%p\n", (void *) &a); // 输出示例：0x7ffee4f0a4c0（地址因运行环境而异）

    // 初始化一维数组，大小为 15
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    // sizeof(b) 返回整个数组的字节大小：15 个 int，每个 int 4 字节（32 位系统），共 60 字节
    printf("%d\n", sizeof(b)); // 输出：60

    // 初始化字符数组，大小为 5，没有空字符 '\0'（不是 C 风格字符串）
    char c_array[] = {'a', 'b', 'c', 'd', 'e'};
    // sizeof(c_array) 返回整个数组的字节大小：5 个 char，每个 char 1 字节，共 5 字节
    printf("%d\n", sizeof(c_array)); // 输出：5

    // 声明一个未初始化的数组，元素值为随机垃圾值
    int d[10];
    // 循环打印数组 d 的每个元素
    for (int i = 0; i < 10; i++) {
        printf("d[%d] = %d\n", i, d[i]); // 输出：d[0] 到 d[9] 的随机值
    }

    // 打印数组 d 的首地址
    // d 是数组名，自动转换为指向第一个元素的指针
    printf("d = %p\n", (void *) d); // 输出示例：0x7ffee4f0a490

    // 打印数组 d 中各元素的地址
    // &d[i] 是第 i 个元素的地址，相邻元素地址差 4 字节（int 大小）
    printf("&d[0] = %p\n", (void *) &d[0]); // 示例：0x7ffee4f0a490
    printf("&d[1] = %p\n", (void *) &d[1]); // 示例：0x7ffee4f0a494
    printf("&d[2] = %p\n", (void *) &d[2]); // 示例：0x7ffee4f0a498
    printf("&d[3] = %p\n", (void *) &d[3]); // 示例：0x7ffee4f0a49c
    printf("&d[4] = %p\n", (void *) &d[4]); // 示例：0x7ffee4f0a4a0

    return 0;
}
