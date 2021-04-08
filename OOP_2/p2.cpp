#include <iostream>
#include <math.h>

using namespace std;

class Rectangle
{
public:
    Rectangle()
        : m_Length(0), m_Breadth(0) {}

    Rectangle(double side)
        : m_Length(side), m_Breadth(side) {}

    Rectangle(double length, double breadth)
        : m_Length(length), m_Breadth(breadth) {}

    double area() { return m_Length * m_Breadth; }

private:
    double m_Length, m_Breadth;
};

int main()
{
    cout << Rectangle().area() << endl;
    cout << Rectangle(10).area() << endl;
    cout << Rectangle(10, 20).area() << endl;

    return 0;
}