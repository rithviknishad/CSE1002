#include <iostream>
#include <string>

using namespace std;

class SmartPrinter
{
public:
    void print(char c, int n) { cout << c << n << endl; }
    void print(int n, char c) { print(c, n); }
};

int main()
{
    SmartPrinter printer;

    printer.print('A', 32);
    printer.print(32, 'A');

    return 0;
}