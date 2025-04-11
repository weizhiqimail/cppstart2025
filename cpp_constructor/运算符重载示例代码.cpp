#include <iostream>
using namespace std;

class Complex {
public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}
    double real, imaginary;
    friend Complex operator+(const Complex &a, const Complex &b);
};

Complex operator+(const Complex &a, const Complex &b) {
    return Complex(a.real + b.real, a.imaginary + b.imaginary);
}

int main() {
    Complex a(1, 2), b(2, 3), c;
    c = a + b;
    cout << "c = (" << c.real << ", " << c.imaginary << "i)" << endl;
    return 0;
}
/* 输出:
c = (3, 5i)
*/