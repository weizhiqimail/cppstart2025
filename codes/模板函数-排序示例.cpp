#include <iostream>

using namespace std;

template <class T>
void templateSwap(T &a, T &b) {
  T temp = a;
  a = b;
  b = temp;
}

/**
 * 模板函数排序
 * @tparam T 类型
 * @param arr 数组元素
 * @param len 数组长度
 * @param flag 正序or倒序
 */
template<class T>
void templateSort(T arr[], int len, bool flag = true) {
  for (int i = 0; i < len; i++) {
    int max = i;
    for(int j = i+1;j<len;j++){
      if (flag) {
        if (arr[max] > arr[j]) {
          max = j;
        }
      } else {
        if (arr[max] < arr[j]) {
          max = j;
        }
      }
    }

    if (max != i) {
      templateSwap(arr[i], arr[max]);
    }
  }
}

template <class T>
void printArray(T arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << "arr[" << i << "] = " << arr[i] << endl;
  }
}

void test1() {
  char arr[] = "swoqabed";
  int len = sizeof(arr)/sizeof(char);
  templateSort(arr, len);
  printArray(arr, len);
}

void test2() {
  int intArr[] = {1, 3, 4, 2, 7, 5, 6};
  int len = sizeof(intArr) / sizeof(int);
  templateSort(intArr, len, false);
  printArray(intArr, len);
}

int main() {
  test1();
  test2();
  return 0;
};