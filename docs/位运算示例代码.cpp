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

// ��λ�����
int bitwiseANDFn() {
    cout << "====== ��λ����� ======" << endl;

    int a = 0x12345678;
    int maskInt = 0xFFFFFF00;
    int resultInt = a & maskInt;

    short s = 0x12FF;
    short maskShort = 0xFF00;
    short resultShort = s & maskShort;

    // ��� int ���͵�������
    cout << "===== int ���������� =====" << endl;
    cout << "===== �� a �ĵ� 8 λ��ȫ������Ϊ 0 =====" << endl;
    cout << "ԭʼ a        = 0x" << hex << uppercase << a
            << " (" << formatBitset(bitset<32>(a)) << ")" << endl;

    cout << "���� maskInt  = 0x" << hex << uppercase << maskInt
            << " (" << formatBitset(bitset<32>(maskInt)) << ")" << endl;

    cout << "��� result   = 0x" << hex << uppercase << resultInt
            << " (" << formatBitset(bitset<32>(resultInt)) << ")" << endl;

    // ��� short ���͵�������
    cout << "\n===== short ���������� =====" << endl;
    cout << "===== �� s �ĵ� 8 λ��ȫ������Ϊ 0 =====" << endl;
    cout << "ԭʼ s        = 0x" << hex << uppercase << s
            << " (" << formatBitset(bitset<16>(s)) << ")" << endl;

    cout << "���� maskShort= 0x" << hex << uppercase << maskShort
            << " (" << formatBitset(bitset<16>(maskShort)) << ")" << endl;

    cout << "��� result   = 0x" << hex << uppercase << resultShort
            << " (" << formatBitset(bitset<16>(resultShort)) << ")" << endl;

    cout << endl;
    return 0;
}

// ��λ�����
int bitwiseORFn() {
    cout << "====== ��λ����� (|) ======" << endl;
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

// ��λ������
int bitwiseXORFn() {
    cout << "��λ��������" << endl;
    cout << "====== ��λ������ (^) ======" << endl;
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

// ��λȡ������
int bitwiseNOTFn() {
    cout << "====== ��λȡ������ (~) ======" << endl;
    int a = 0x0F0F0F0F;
    int result = ~a;

    cout << "a        = 0x" << hex << uppercase << a
            << "  (" << formatBitset(bitset<32>(a)) << ")" << endl;
    cout << "~a       = 0x" << hex << uppercase << result
            << " (" << formatBitset(bitset<32>(result)) << ")" << endl;
    cout << endl;
    return 0;
}

// ���Ʋ���
int leftShiftFn() {
    cout << "���Ʋ�����" << endl;
    cout << "====== ���Ʋ��� (<<) ======" << endl;
    int a = 0x0000000F;
    int shift = 4;
    int result = a << shift;

    cout << "a        = 0x" << hex << uppercase << a
            << " (" << formatBitset(bitset<32>(a)) << ")" << endl;
    cout << "a << " << shift << "  = 0x" << hex << uppercase << result
            << " (" << formatBitset(bitset<32>(result)) << ")" << endl;
    cout << endl;
    return 0;
}

// ���Ʋ���
int rightShiftFn() {
    cout << "====== ���Ʋ��� (>>) ======" << endl;
    int a = 0xF0000000;
    int shift = 4;
    int result = a >> shift;

    cout << "a        = 0x" << hex << uppercase << a
            << " (" << formatBitset(bitset<32>(a)) << ")" << endl;
    cout << "a >> " << shift << "  = 0x" << hex << uppercase << result
            << "  (" << formatBitset(bitset<32>(result)) << ")" << endl;

    cout << endl;
    return 0;
}


int main() {
    // ��λ�����
    bitwiseANDFn();

    // ��λ�����
    bitwiseORFn();

    // ��λ������
    bitwiseXORFn();

    // ��λȡ������
    bitwiseNOTFn();

    // ���Ʋ���
    leftShiftFn();

    // ���Ʋ���
    rightShiftFn();

    return 0;
}

/**
 * ʾ������������

====== ��λ����� ======
===== int ���������� =====
===== �� a �ĵ� 8 λ��ȫ������Ϊ 0 =====
ԭʼ a        = 0x12345678 (0001 0010 0011 0100 0101 0110 0111 1000)
���� maskInt  = 0xFFFFFF00 (1111 1111 1111 1111 1111 1111 0000 0000)
��� result   = 0x12345600 (0001 0010 0011 0100 0101 0110 0000 0000)

===== short ���������� =====
===== �� s �ĵ� 8 λ��ȫ������Ϊ 0 =====
ԭʼ s        = 0x12FF (0001 0010 1111 1111)
���� maskShort= 0xFF00 (1111 1111 0000 0000)
��� result   = 0x1200 (0001 0010 0000 0000)

====== ��λ����� (|) ======
a        = 0xF0F0F0F  (0000 1111 0000 1111 0000 1111 0000 1111)
b        = 0x33333333 (0011 0011 0011 0011 0011 0011 0011 0011)
a | b    = 0x3F3F3F3F (0011 1111 0011 1111 0011 1111 0011 1111)

��λ��������
====== ��λ������ (^) ======
a        = 0xAAAA5555 (1010 1010 1010 1010 0101 0101 0101 0101)
b        = 0xFFFF0000 (1111 1111 1111 1111 0000 0000 0000 0000)
a ^ b    = 0x55555555 (0101 0101 0101 0101 0101 0101 0101 0101)

====== ��λȡ������ (~) ======
a        = 0xF0F0F0F  (0000 1111 0000 1111 0000 1111 0000 1111)
~a       = 0xF0F0F0F0 (1111 0000 1111 0000 1111 0000 1111 0000)

���Ʋ�����
====== ���Ʋ��� (<<) ======
a        = 0xF (0000 0000 0000 0000 0000 0000 0000 1111)
a << 4  = 0xF0 (0000 0000 0000 0000 0000 0000 1111 0000)

====== ���Ʋ��� (>>) ======
a        = 0xF0000000 (1111 0000 0000 0000 0000 0000 0000 0000)
a >> 4  = 0xFF000000  (1111 1111 0000 0000 0000 0000 0000 0000)

 */
