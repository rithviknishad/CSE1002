#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee
{
public:
    Employee(string name, int yearOfJoin, double salary, string address)
        : m_Name(name), m_YearOfJoin(yearOfJoin), m_Salary(salary), m_Address(address) {}

    void print()
    {
        cout << setw(16) << m_Name << setw(8) << m_YearOfJoin << '\t' << m_Address << endl;
    }

private:
    string m_Name, m_Address;
    int m_YearOfJoin;
    double m_Salary;
};

int main()
{
    cout << setw(16) << "Name" << setw(8) << "Year" << '\t' << "Address" << endl;

    Employee("Robert", 1994, 1000, "64C Wall Street").print();
    Employee("Sam", 2000, 1000, "68D Wall Street").print();
    Employee("John", 1999, 1000, "26B Wall Street").print();

    return 0;
}