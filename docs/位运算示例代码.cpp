#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;

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

// 按位与操作
int bitwiseANDFn() {
    cout << "====== 按位与操作 ======" << endl;

    int a = 0x12345678;
    int maskInt = 0xFFFFFF00;
    int resultInt = a & maskInt;

    short s = 0x12FF;
    short maskShort = 0xFF00;
    short resultShort = s & maskShort;

    // 输出 int 类型的与运算
    cout << "===== int 类型与运算 =====" << endl;
    cout << "===== 将 a 的低 8 位，全部都置为 0 =====" << endl;
    cout << "原始 a        = 0x" << hex << uppercase << a
            << " (" << formatBitset(bitset<32>(a)) << ")" << endl;

    cout << "掩码 maskInt  = 0x" << hex << uppercase << maskInt
            << " (" << formatBitset(bitset<32>(maskInt)) << ")" << endl;

    cout << "结果 result   = 0x" << hex << uppercase << resultInt
            << " (" << formatBitset(bitset<32>(resultInt)) << ")" << endl;

    // 输出 short 类型的与运算
    cout << "\n===== short 类型与运算 =====" << endl;
    cout << "===== 将 s 的低 8 位，全部都置为 0 =====" << endl;
    cout << "原始 s        = 0x" << hex << uppercase << s
            << " (" << formatBitset(bitset<16>(s)) << ")" << endl;

    cout << "掩码 maskShort= 0x" << hex << uppercase << maskShort
            << " (" << formatBitset(bitset<16>(maskShort)) << ")" << endl;

    cout << "结果 result   = 0x" << hex << uppercase << resultShort
            << " (" << formatBitset(bitset<16>(resultShort)) << ")" << endl;

    cout << endl;
    return 0;
}

/*
====== 按位与操作 ======
===== int 类型与运算 =====
===== 将 a 的低 8 位，全部都置为 0 =====
原始 a        = 0x12345678 (0001 0010 0011 0100 0101 0110 0111 1000)
掩码 maskInt  = 0xFFFFFF00 (1111 1111 1111 1111 1111 1111 0000 0000)
结果 result   = 0x12345600 (0001 0010 0011 0100 0101 0110 0000 0000)

===== short 类型与运算 =====
===== 将 s 的低 8 位，全部都置为 0 =====
原始 s        = 0x12FF (0001 0010 1111 1111)
掩码 maskShort= 0xFF00 (1111 1111 0000 0000)
结果 result   = 0x1200 (0001 0010 0000 0000)
 */

// 按位或操作
int bitwiseORFn() {
    cout << "====== 按位或操作 (|) ======" << endl;
    int a = 0x0F0F0F0F;
    int b = 0x33333333;
    int result = a | b;

    cout << "a        = 0x" << hex << uppercase << a
            << "  (" << formatBitset(bitset<32>(a)) << ")" << endl;
    cout << "b        = 0x" << hex << uppercase << b
            << " (" << formatBitset(bitset<32>(b)) << ")" << endl;
    cout << "a | b    = 0x" << hex << uppercase << result
            << " (" << formatBitset(bitset<32>(result)) << ")" << endl;
    cout << endl;
    return 0;
}
/*
====== 按位或操作 (|) ======
a        = 0x0F0F0F0F  (0000 1111 0000 1111 0000 1111 0000 1111)
b        = 0x33333333 (0011 0011 0011 0011 0011 0011 0011 0011)
a | b    = 0x3F3F3F3F (0011 1111 0011 1111 0011 1111 0011 1111)
 */


// 按位异或操作
int bitwiseXORFn() {
    cout << "按位异或操作：" << endl;
    cout << "====== 按位异或操作 (^) ======" << endl;
    int a = 0xAAAA5555;
    int b = 0xFFFF0000;
    int result = a ^ b;

    cout << "a        = 0x" << hex << uppercase << a
            << " (" << formatBitset(bitset<32>(a)) << ")" << endl;
    cout << "b        = 0x" << hex << uppercase << b
            << " (" << formatBitset(bitset<32>(b)) << ")" << endl;
    cout << "a ^ b    = 0x" << hex << uppercase << result
            << " (" << formatBitset(bitset<32>(result)) << ")" << endl;
    cout << endl;
    return 0;
}

/*
按位异或操作：
====== 按位异或操作 (^) ======
a        = 0xAAAA5555 (1010 1010 1010 1010 0101 0101 0101 0101)
b        = 0xFFFF0000 (1111 1111 1111 1111 0000 0000 0000 0000)
a ^ b    = 0x55555555 (0101 0101 0101 0101 0101 0101 0101 0101)
 */

// 按位取反操作
int bitwiseNOTFn() {
    cout << "====== 按位取反操作 (~) ======" << endl;
    int a = 0x0F0F0F0F;
    int result = ~a;

    cout << "a        = 0x" << hex << uppercase << a
            << "  (" << formatBitset(bitset<32>(a)) << ")" << endl;
    cout << "~a       = 0x" << hex << uppercase << result
            << " (" << formatBitset(bitset<32>(result)) << ")" << endl;
    cout << endl;
    return 0;
}
/*
====== 按位取反操作 (~) ======
a        = 0x0F0F0F0F  (0000 1111 0000 1111 0000 1111 0000 1111)
~a       = 0xF0F0F0F0 (1111 0000 1111 0000 1111 0000 1111 0000)
 */

// 左移操作
int leftShiftFn() {
    cout << "====== 左移操作 (<<) ======" << endl;
    int a = 0x0000000F;
    int shift = 4;
    int result = a << shift;

    cout << "a        = 0x" << hex << uppercase << a
            << " (" << formatBitset(bitset<32>(a)) << ")" << endl;
    cout << "a << " << shift << "  = 0x" << hex << uppercase << result
            << " (" << formatBitset(bitset<32>(result)) << ")" << endl;

    cout << endl;
    cout << "====== 左移操作 (<<) 移位 35 位，即超过 32 位 ======" << endl;

    // 示例 1: 正数左移
    int a_pos = 0x0000000F; // 00001111
    int shift_pos = 35; // 超过 32 位的左移
    int result_pos = a_pos << shift_pos;

    cout << "正数 a        = 0x" << hex << uppercase << a_pos
            << " (" << formatBitset(bitset<32>(a_pos)) << ")" << endl;
    cout << "a << " <<  dec << shift_pos << "     = 0x" << hex << uppercase << result_pos
            << " (" << formatBitset(bitset<32>(result_pos)) << ")" << endl;

    // 示例 2: 负数左移
    int a_neg = 0xF0000000; // 11110000 00000000 00000000 00000000 (负数)
    int shift_neg = 35; // 超过 32 位的左移
    int result_neg = a_neg << shift_neg;

    cout << "负数 a        = 0x" << hex << uppercase << a_neg
            << " (" << formatBitset(bitset<32>(a_neg)) << ")" << endl;
    cout << "a << " <<  dec << shift_neg << "      = 0x" << hex << uppercase << result_neg
            << " (" << formatBitset(bitset<32>(result_neg)) << ")" << endl;
    cout << endl;
    return 0;
}

/**
====== 左移操作 (<<) ======
a        = 0xF (0000 0000 0000 0000 0000 0000 0000 1111)
a << 4  = 0xF0 (0000 0000 0000 0000 0000 0000 1111 0000)

====== 左移操作 (<<) 移位 35 位，即超过 32 位 ======
正数 a        = 0xF (0000 0000 0000 0000 0000 0000 0000 1111)
a << 35     = 0x78 (0000 0000 0000 0000 0000 0000 0111 1000)
负数 a        = 0xF0000000 (1111 0000 0000 0000 0000 0000 0000 0000)
a << 35      = 0x80000000 (1000 0000 0000 0000 0000 0000 0000 0000)
 */

// 右移操作
int rightShiftFn() {
    cout << "====== 右移操作 (>>) ======" << endl;
    int a = 0xF0000000;
    int shift = 4;
    int result = a >> shift;

    cout << "a        = 0x" << hex << uppercase << a
            << " (" << formatBitset(bitset<32>(a)) << ")" << endl;
    cout << "a >> " << shift << "   = 0x" << hex << uppercase << result
            << " (" << formatBitset(bitset<32>(result)) << ")" << endl;

    cout << endl;

    cout << "====== 右移操作 (>>) 移位 35 位，即超过 32 位 ======" << endl;

    // 示例 1: 正数右移
    int a_pos = 0xF0000000; // 11110000 00000000 00000000 00000000
    int shift_pos = 35; // 超过 32 位的右移
    int result_pos = a_pos >> shift_pos;

    cout << "正数 a        = 0x" << hex << uppercase << a_pos
            << " (" << formatBitset(bitset<32>(a_pos)) << ")" << endl;
    cout << "a >> " << dec << shift_pos << "      = 0x" << hex << uppercase << result_pos
            << " (" << formatBitset(bitset<32>(result_pos)) << ")" << endl;

    // 示例 2: 负数右移
    int a_neg = 0xF0000000; // 11110000 00000000 00000000 00000000 (负数)
    int shift_neg = 35; // 超过 32 位的右移
    int result_neg = a_neg >> shift_neg;

    cout << "负数 a        = 0x" << hex << uppercase << a_neg
            << " (" << formatBitset(bitset<32>(a_neg)) << ")" << endl;
    cout << "a >> " <<  dec << shift_neg << "      = 0x" << hex << uppercase << result_neg
            << " (" << formatBitset(bitset<32>(result_neg)) << ")" << endl;
    cout << endl;
    return 0;
}

/*
====== 右移操作 (>>) ======
a        = 0xF0000000 (1111 0000 0000 0000 0000 0000 0000 0000)
a >> 4   = 0xFF000000 (1111 1111 0000 0000 0000 0000 0000 0000)

====== 右移操作 (>>) 移位 35 位，即超过 32 位 ======
正数 a        = 0xF0000000 (1111 0000 0000 0000 0000 0000 0000 0000)
a >> 35      = 0xFE000000 (1111 1110 0000 0000 0000 0000 0000 0000)
负数 a        = 0xF0000000 (1111 0000 0000 0000 0000 0000 0000 0000)
a >> 35      = 0xFE000000 (1111 1110 0000 0000 0000 0000 0000 0000)

 */

int main() {
    // 按位与操作
    bitwiseANDFn();

    // 按位或操作
    bitwiseORFn();

    // 按位异或操作
    bitwiseXORFn();

    // 按位取反操作
    bitwiseNOTFn();

    // 左移操作
    leftShiftFn();

    // 右移操作
    rightShiftFn();

    return 0;
}
