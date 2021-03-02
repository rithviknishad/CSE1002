#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    float salary, workHoursPerDay;
} Employee;

void readEmployeeDetails(Employee *employee)
{
    static char _buffer[64];
    static int _bufferUsed;

    printf("Employee Name   : ");
    scanf("%s%n", _buffer, &_bufferUsed);

    employee->name = malloc(sizeof(char) * _bufferUsed);
    strcpy(employee->name, _buffer);

    printf("Salary          : ");
    scanf("%f", &(employee->salary));

    printf("Work hours/day  : ");
    scanf("%f", &(employee->workHoursPerDay));

    printf("\n");
}

void printEmployeeDetails(const Employee *employee)
{
    printf("Employee : {"
           "\n\t'Name'            : '%s',"
           "\n\t'Salary'          : %f,"
           "\n\t'Work hours/day'  : %f,"
           "\n}\n",
           employee->name, employee->salary, employee->workHoursPerDay);
}

void forEach(Employee *head, int n, void (*delegate)(Employee *))
{
    while (n--)
        delegate(head++);
}

float conditionallyRaiseSalary(Employee *employee)
{
    if (employee->workHoursPerDay >= 12)
        return employee->salary += 150.0;

    if (employee->workHoursPerDay >= 10)
        return employee->salary += 100.0;

    if (employee->workHoursPerDay >= 8)
        return employee->salary += 50.0;
}

void main()
{
    int nEmployees;

    printf("Number of employees: ");
    scanf("%d", &nEmployees);

    Employee *employees = (Employee *)malloc(sizeof(Employee) * nEmployees);

    forEach(employees, nEmployees, readEmployeeDetails);
    forEach(employees, nEmployees, conditionallyRaiseSalary);
    forEach(employees, nEmployees, printEmployeeDetails);
}