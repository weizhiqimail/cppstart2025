#include <iostream>

using namespace std;

int main() {
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
}
