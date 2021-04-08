#include <iostream>
#include <math.h>

using namespace std;

class Area
{
public:
    Area(double length, double breadth)
    {
        m_Length = length;
        m_Breadth = breadth;
    }

    double getArea()
    {
        return m_Length * m_Breadth;
    }

private:
    double m_Length, m_Breadth;
};

int main()
{
    cout << "Area(a) = " << Area(2, 4).getArea() << endl;
    return 0;
}