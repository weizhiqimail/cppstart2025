#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    vector<int> result(v.size());

    int scale = 2;
    int offset = 10;

    // transform(v.begin(), v.end(), result.begin(), [scale, offset](int x, int &y) -> int {
    //     cout << "x: " << x << ", y: " << y << endl;
    //     y = x * scale + offset;
    //     return y;
    // });

    transform(v.begin(), v.end(), result.begin(),
              [scale, offset](int x) -> int {
                  cout << x << "\t";
                  return x * scale + offset;; // transform 需要返回值
              });
    cout << endl;

    auto it = result.begin();
    while (it != result.end()) {
        cout << *it << "\t";
        ++it;
    }
}
