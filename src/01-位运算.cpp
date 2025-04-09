#include <iostream>
#include <bitset>
#include <string>
#include <iomanip>
using namespace std;

// �����ʽ�� bitset �����ÿ4λ�ӿո�
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

// ���Ʋ���������32λ�������������͸���
int leftShiftOverflowFn() {
    cout << "====== ���Ʋ��� (<<) ���� 32 λ ======" << endl;

    // ʾ�� 1: ��������
    int a_pos = 0x0000000F;  // 00001111
    int shift_pos = 35;      // ���� 32 λ������
    int result_pos = a_pos << shift_pos;

    cout << "���� a        = 0x" << hex << uppercase << a_pos
         << " (" << formatBitset(bitset<32>(a_pos)) << ")" << endl;
    cout << "a << " << shift_pos << "      = 0x" << hex << uppercase << result_pos
         << " (" << formatBitset(bitset<32>(result_pos)) << ")" << endl;

    // ʾ�� 2: ��������
    int a_neg = 0xF0000000;  // 11110000 00000000 00000000 00000000 (����)
    int shift_neg = 35;      // ���� 32 λ������
    int result_neg = a_neg << shift_neg;

    cout << "���� a        = 0x" << hex << uppercase << a_neg
         << " (" << formatBitset(bitset<32>(a_neg)) << ")" << endl;
    cout << "a << " << shift_neg << "      = 0x" << hex << uppercase << result_neg
         << " (" << formatBitset(bitset<32>(result_neg)) << ")" << endl;

    cout << endl;
    return 0;
}

// ���Ʋ���������32λ�������������͸���
int rightShiftOverflowFn() {
    cout << "====== ���Ʋ��� (>>) ���� 32 λ ======" << endl;

    // ʾ�� 1: ��������
    int a_pos = 0xF0000000;  // 11110000 00000000 00000000 00000000
    int shift_pos = 35;      // ���� 32 λ������
    int result_pos = a_pos >> shift_pos;

    cout << "���� a        = 0x" << hex << uppercase << a_pos
         << " (" << formatBitset(bitset<32>(a_pos)) << ")" << endl;
    cout << "a >> " << shift_pos << "      = 0x" << hex << uppercase << result_pos
         << " (" << formatBitset(bitset<32>(result_pos)) << ")" << endl;

    // ʾ�� 2: ��������
    int a_neg = 0xF0000000;  // 11110000 00000000 00000000 00000000 (����)
    int shift_neg = 35;      // ���� 32 λ������
    int result_neg = a_neg >> shift_neg;

    cout << "���� a        = 0x" << hex << uppercase << a_neg
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
