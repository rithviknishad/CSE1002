#include <iostream>
#include <math.h>

using namespace std;

class Volume
{
public:
    double volume;

    Volume(double length, double breadth, double height)
        : volume(length * breadth * height) {}
};

int main()
{

    cout << "Volume = " << Volume(2, 3, 5).volume;

    return 0;
}