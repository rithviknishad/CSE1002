#include <iostream>
#include <math.h>

using namespace std;

class Triangle
{
public:
    Triangle(double a, double b, double c)
        : m_Sides({a, b, c}) {}

    double perimeter() { return m_Sides[0] + m_Sides[1] + m_Sides[2]; }

    double area()
    {
        double s = perimeter() / 2.0;
        return sqrt(s * (s - m_Sides[0]) * (s - m_Sides[1]) * (s - m_Sides[2]));
    }

private:
    double m_Sides[3];
};

int main()
{
    Triangle a = Triangle(3, 4, 5);

    cout << "Perimeter = " << a.perimeter() << endl;
    cout << "Area = " << a.area() << endl;

    return 0;
}