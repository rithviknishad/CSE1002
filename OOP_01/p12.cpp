#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define INCHES *2.54
#define FEET *30.48
#define METERS *100;

class Distance
{
public:
    Distance(double centimeters) : value_cm(centimeters) {}

    Distance operator+(const Distance &d)
    {
        return Distance(value_cm + d.value_cm);
    }

    double value_cm;
};

int main()
{
    Distance
        a = Distance(3 INCHES),
        b = Distance(4 FEET);

    cout << (a + b).value_cm << endl;
    return 0;
}