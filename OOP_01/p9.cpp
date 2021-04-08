#include <iostream>
#include <math.h>

using namespace std;

class Complex
{
    double r, i;

public:
    Complex(double real, double img) : r(real), i(img) {}

    Complex operator+(const Complex &c) { return Complex(r + c.r, i + c.i); }
    Complex operator-(const Complex &c) { return Complex(r - c.r, i - c.i); }
    Complex operator*(const Complex &c)
    {
        return Complex((r * c.r) - (i * c.i), (r * c.i) + (c.r * i));
    }

    void print() { cout << '(' << r << " + " << i << "i)" << endl; }
};

int main()
{
    Complex
        a = Complex(3, 4),
        b = Complex(3, 4);

    cout << "a + b = ";
    (a + b).print();

    cout << "a - b = ";
    (a - b).print();

    cout << "a * b = ";
    (a * b).print();

    return 0;
}