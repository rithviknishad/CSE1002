#include <iostream>
#include <string>
#include <list>

using namespace std;

class Employee
{
public:
    string name;
    string id;

    double basicPay = 0, da_percentage = 0, hra = 0, totalSalary = 0;

    void getInput()
    {
        cin >> name >> id >> basicPay >> da_percentage >> hra;
        totalSalary = basicPay + (da_percentage * basicPay / 100.0) + hra;
    }
};

int main()
{
    list<Employee> employees;

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        Employee e = Employee();
        e.getInput();
        employees.push_back(e);
    }

    for (auto const &e : employees)
        cout << e.id << endl
             << e.totalSalary << endl;

    return 0;
}