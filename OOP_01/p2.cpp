#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    Student(string name, int rollNumber, string phoneNumber)
    {
        m_Name = name;
        m_RollNumber = rollNumber;
        m_PhoneNumber = phoneNumber;
    }

    void print()
    {
        cout << m_Name << '\t' << m_RollNumber << '\t' << m_PhoneNumber << endl;
    }

private:
    string m_Name;
    int m_RollNumber;
    string m_PhoneNumber;
};

int main()
{
    Student("Sam", 20, "+91 8888 000 333").print();
    Student("John", 30, "+91 8887 000 332").print();

    return 0;
}