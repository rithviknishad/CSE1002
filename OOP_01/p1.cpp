#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    string name;
    int rollNumber;
};

int main()
{
    Student s;

    s.name = "John";
    s.rollNumber = 2;

    cout << s.name << '\t' << s.rollNumber << endl;

    return 0;
}