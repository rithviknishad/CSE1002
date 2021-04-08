#include <iostream>
#include <math.h>

using namespace std;

class Area
{
public:
    void setDimensions(double length, double breadth)
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
    Area a;
    a.setDimensions(2, 4);

    cout << "Area(a) = " << a.getArea() << endl;

    return 0;
}