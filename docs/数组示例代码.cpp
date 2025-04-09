#include <bitset>   // ����λ��ͷ�ļ�
#include <stdio.h> // ������׼�������ͷ�ļ�
#include <iostream> // �������������ͷ�ļ�

using namespace std; // ʹ�ñ�׼�����ռ�

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

// ��װ���һά����ĺ��������ӿ�ѡ���� showAddress
template<typename T, size_t N>
void printArray(const string &arrName, T (&arr)[N], bool showAddress = false) {
    cout << "===== һά����Ԫ�� (" << arrName << ") ��� =====\n";
    for (size_t i = 0; i < N; i++) {
        cout << arrName << "[" << i << "] = " << arr[i];
        if (showAddress) {
            // ��ָ��ת��Ϊ�������� uintptr_t
            uintptr_t addr = reinterpret_cast<uintptr_t>(&arr[i]);
            cout << "\t(" << &arr[i] << ")";           // �����ַ
            cout << "\t" << formatBitset(bitset<32>(addr)); // �����ַ�� 32 λ������
        }
        cout << "\n";
    }
    cout << "\n";
}

// ��װ�����ά����ĺ��������ӿ�ѡ���� showAddress
template<typename T, size_t Rows, size_t Cols>
void print2DArray(const string &arrName, T (&arr)[Rows][Cols], bool showAddress = false) {
    cout << "===== ��ά����Ԫ�� (" << arrName << ") ��� =====\n";
    for (size_t i = 0; i < Rows; i++) {
        for (size_t j = 0; j < Cols; j++) {
            cout << arrName << "[" << i << "][" << j << "] = " << arr[i][j];
            if (showAddress) {
                // ��ָ��ת��Ϊ�������� uintptr_t
                uintptr_t addr = reinterpret_cast<uintptr_t>(&arr[i][j]);
                cout << "\t(" << &arr[i][j] << ")";         // �����ַ
                cout << "\t" << formatBitset(bitset<32>(addr)); // �����ַ�� 32 λ������
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
    // ��ʼ��һά���飬����Ԫ��Ϊ 0
    // ָֻ����һ��Ԫ��Ϊ 0������Ԫ���Զ����Ϊ 0
    int c[10] = {1};
    printText("��ʼ��һά���� c[10]������Ԫ��Ϊ 0��ָֻ����һ��Ԫ��Ϊ 1������Ԫ���Զ����Ϊ 0");
    printArray("c", c, true);
    cout << "c: " <<c << endl;
    cout << "&c:" << &c << endl;

    // ��ʼ����ά���飬����Ԫ��Ϊ 0
    // ʹ��Ƕ�׳�ʼ���б���ʽָ��ÿ��Ԫ��
    int c1[3][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    printText("��ʼ����ά���� c1[3][4]������Ԫ��Ϊ 0��ʹ��Ƕ�׳�ʼ���б���ʽָ��ÿ��Ԫ��");
    print2DArray("c1", c1, true);

    // ��ʼ����ά���飬���ṩ����Ԫ��
    // {1, 2, 3, 4} �ᰴ����� c2[0][0] �� c2[0][3]������Ԫ���Զ�Ϊ 0
    int c2[3][4] = {1, 2, 3, 4};
    printText("��ʼ����ά���� c2[3][4]�����ṩ����Ԫ�أ�{1, 2, 3, 4} �ᰴ����� c2[0][0] �� c2[0][3]������Ԫ���Զ�Ϊ 0");
    print2DArray("c2", c2, true);

    // ��ʼ��һά���飬���������ݳ�ʼ���б��ƶϴ�СΪ 10
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printText("��ʼ��һά���� a[]�����������ݳ�ʼ���б��ƶϴ�СΪ 10");
    // ��ӡ���� a ���׵�ַ��%p ��Ҫ void* ����ָ��
    printf("%p\n", (void *) &a); // ���ʾ����0x7ffee4f0a4c0����ַ�����л������죩

    // ��ʼ��һά���飬��СΪ 15
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    // sizeof(b) ��������������ֽڴ�С��15 �� int��ÿ�� int 4 �ֽڣ�32 λϵͳ������ 60 �ֽ�
    printf("%d\n", sizeof(b)); // �����60

    // ��ʼ���ַ����飬��СΪ 5��û�п��ַ� '\0'������ C ����ַ�����
    char c_array[] = {'a', 'b', 'c', 'd', 'e'};
    // sizeof(c_array) ��������������ֽڴ�С��5 �� char��ÿ�� char 1 �ֽڣ��� 5 �ֽ�
    printf("%d\n", sizeof(c_array)); // �����5

    // ����һ��δ��ʼ�������飬Ԫ��ֵΪ�������ֵ
    int d[10];
    // ѭ����ӡ���� d ��ÿ��Ԫ��
    for (int i = 0; i < 10; i++) {
        printf("d[%d] = %d\n", i, d[i]); // �����d[0] �� d[9] �����ֵ
    }

    // ��ӡ���� d ���׵�ַ
    // d �����������Զ�ת��Ϊָ���һ��Ԫ�ص�ָ��
    printf("d = %p\n", (void *) d); // ���ʾ����0x7ffee4f0a490

    // ��ӡ���� d �и�Ԫ�صĵ�ַ
    // &d[i] �ǵ� i ��Ԫ�صĵ�ַ������Ԫ�ص�ַ�� 4 �ֽڣ�int ��С��
    printf("&d[0] = %p\n", (void *) &d[0]); // ʾ����0x7ffee4f0a490
    printf("&d[1] = %p\n", (void *) &d[1]); // ʾ����0x7ffee4f0a494
    printf("&d[2] = %p\n", (void *) &d[2]); // ʾ����0x7ffee4f0a498
    printf("&d[3] = %p\n", (void *) &d[3]); // ʾ����0x7ffee4f0a49c
    printf("&d[4] = %p\n", (void *) &d[4]); // ʾ����0x7ffee4f0a4a0

    return 0;
}
