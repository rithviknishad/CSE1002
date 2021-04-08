#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    string name;

    Student(string name = "Unknown")
        : name(name) {}
};

int main()
{
    cout << Student().name << endl;
    cout << Student("Aswin Murali").name << endl;
    return 0;
}