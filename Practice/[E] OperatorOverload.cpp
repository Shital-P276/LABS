#include <iostream>
using namespace std;

class Complex {
private:
    int a, b;
public:
    // Constructor to initialize complex numbers
    Complex(int real = 0, int imag = 0) : a(real), b(imag) {}

    // Overload + operator
    Complex operator+(const Complex &other) {
        return Complex(a + other.a, b + other.b);
    }

    // Overload << operator
    friend ostream &operator<<(ostream &out, const Complex &c) {
        out << c.a << "+i" << c.b;
        return out;
    }
};

int main() {
    // Direct initialization of complex numbers
    Complex x(3, 4);  // 3 + 4i
    Complex y(1, 2);  // 1 + 2i

    // Add two complex numbers
    Complex z = x + y;

    // Print the result
    cout << z << endl;  // Output: 4+i6

    return 0;
}
