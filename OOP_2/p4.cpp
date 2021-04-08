#include <iostream>
#include <math.h>

using namespace std;

class Programming
{
public:
    Programming(string suffix = "programming languages")
    {
        cout << "I love " << suffix << endl;
    }
};

int main()
{
    Programming();
    Programming("dart, python and c++");

    return 0;
}