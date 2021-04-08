#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int experience;
    float salary;
} Employee;

void readEmployeeDetails(Employee *employee)
{
    static char _buffer[64];
    static int _bufferUsed;

    printf("Employee name       : ");
    scanf("%s%n", _buffer, &_bufferUsed);

    employee->name = malloc(sizeof(char) * _bufferUsed);
    strcpy(employee->name, _buffer);

    printf("Experience          : ");
    scanf("%d", &(employee->experience));

    printf("Current Salary      : ");
    scanf("%f", &(employee->salary));

    printf("\n");
}

void printEmployeeDetails(const Employee *employee)
{
    printf("%s \t Experience: %d \t Revised Salary: %.2f INR\n",
           employee->name, employee->experience, employee->salary);
}

void forEach(Employee *head, int n, const void (*delegate)(Employee *))
{
    while (n--)
        delegate(head++);
}

void reviseSalary(Employee *employee)
{
    if (employee->experience > 15)
        (employee->salary) *= 1.1; // Raise by 10%
}

void main()
{
    int nEmployees;

    printf("Number of employees to enter: ");
    scanf("%d", &nEmployees);

    Employee *employees = (Employee *)malloc(sizeof(Employee) * nEmployees);

    forEach(employees, nEmployees, readEmployeeDetails);
    forEach(employees, nEmployees, reviseSalary);
    forEach(employees, nEmployees, printEmployeeDetails);
}