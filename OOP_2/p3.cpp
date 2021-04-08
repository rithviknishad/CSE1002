#include <iostream>
#include <math.h>

using namespace std;

class AddAmount
{
public:
    double amount = 50;

    AddAmount(double incrValue = 0) { amount += incrValue; }
};

int main()
{
    cout << AddAmount().amount << endl;
    cout << AddAmount(25).amount << endl;

    return 0;
}