#include <iostream>
#include <exception>

using namespace std;

struct DivideByZeroError : public std::exception
{
    const char *what() const throw()
    {
        return "Encountered Divide By Zero Error";
    }
};

int main()
{
    int n, v2, n1, n2;
    float v1;

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> v2 >> n1 >> n2;
        v1 = n1 * v2 / n2;
    }

    if (v1 < 230)
        cout << "Less";
    else
        cout << "More";
    return 0;
}