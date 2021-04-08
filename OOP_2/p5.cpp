#include <iostream>
#include <math.h>

using namespace std;

class PrintNumber
{
public:
    void printn(double a) { cout << a << endl; }
    void printn(float a) { printn(double(a)); }
    void printn(int a) { printn(double(a)); }
};

int main()
{
    PrintNumber printer;

    int a = 10;
    float b = 12.0f;
    double c = M_PI;

    printer.printn(a);
    printer.printn(b);
    printer.printn(c);

    return 0;
}