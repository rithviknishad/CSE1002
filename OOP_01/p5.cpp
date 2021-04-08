#include <iostream>
#include <math.h>

using namespace std;

class Rectangle
{
public:
    Rectangle(double length, double breadth)
        : m_Length(length), m_Breadth(breadth) {}

    double perimeter() { return (m_Length + m_Breadth) * 2.0; }

    double area()
    {
        return m_Length * m_Breadth;
    }

private:
    double m_Length, m_Breadth;
};

int main()
{
    Rectangle a = Rectangle(4, 5), b = Rectangle(5, 8);

    cout << "Area(a) = " << a.area() << endl;
    cout << "Area(b) = " << b.area() << endl;

    return 0;
}