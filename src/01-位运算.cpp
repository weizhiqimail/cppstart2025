#include <iostream>
#include <bitset>
#include <string>
#include <iomanip>
using namespace std;

// 分组格式化 bitset 输出，每4位加空格
template<size_t N>
string formatBitset(const bitset<N>& b) {
    string raw = b.to_string();
    string formatted;
    for (size_t i = 0; i < raw.size(); ++i) {
        formatted += raw[i];
        if ((i + 1) % 4 == 0 && i != raw.size() - 1)
            formatted += ' ';
    }
    return formatted;
}

// 左移操作（超过32位），包括正数和负数
int leftShiftOverflowFn() {
    cout << "====== 左移操作 (<<) 超过 32 位 ======" << endl;

    // 示例 1: 正数左移
    int a_pos = 0x0000000F;  // 00001111
    int shift_pos = 35;      // 超过 32 位的左移
    int result_pos = a_pos << shift_pos;

    cout << "正数 a        = 0x" << hex << uppercase << a_pos
         << " (" << formatBitset(bitset<32>(a_pos)) << ")" << endl;
    cout << "a << " << shift_pos << "      = 0x" << hex << uppercase << result_pos
         << " (" << formatBitset(bitset<32>(result_pos)) << ")" << endl;

    // 示例 2: 负数左移
    int a_neg = 0xF0000000;  // 11110000 00000000 00000000 00000000 (负数)
    int shift_neg = 35;      // 超过 32 位的左移
    int result_neg = a_neg << shift_neg;

    cout << "负数 a        = 0x" << hex << uppercase << a_neg
         << " (" << formatBitset(bitset<32>(a_neg)) << ")" << endl;
    cout << "a << " << shift_neg << "      = 0x" << hex << uppercase << result_neg
         << " (" << formatBitset(bitset<32>(result_neg)) << ")" << endl;

    cout << endl;
    return 0;
}

// 右移操作（超过32位），包括正数和负数
int rightShiftOverflowFn() {
    cout << "====== 右移操作 (>>) 超过 32 位 ======" << endl;

    // 示例 1: 正数右移
    int a_pos = 0xF0000000;  // 11110000 00000000 00000000 00000000
    int shift_pos = 35;      // 超过 32 位的右移
    int result_pos = a_pos >> shift_pos;

    cout << "正数 a        = 0x" << hex << uppercase << a_pos
         << " (" << formatBitset(bitset<32>(a_pos)) << ")" << endl;
    cout << "a >> " << shift_pos << "      = 0x" << hex << uppercase << result_pos
         << " (" << formatBitset(bitset<32>(result_pos)) << ")" << endl;

    // 示例 2: 负数右移
    int a_neg = 0xF0000000;  // 11110000 00000000 00000000 00000000 (负数)
    int shift_neg = 35;      // 超过 32 位的右移
    int result_neg = a_neg >> shift_neg;

    cout << "负数 a        = 0x" << hex << uppercase << a_neg
         << " (" << formatBitset(bitset<32>(a_neg)) << ")" << endl;
    cout << "a >> " << shift_neg << "      = 0x" << hex << uppercase << result_neg
         << " (" << formatBitset(bitset<32>(result_neg)) << ")" << endl;

    cout << endl;
    return 0;
}

int main() {
    leftShiftOverflowFn();
    rightShiftOverflowFn();
    return 0;
}
