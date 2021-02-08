#include <stdio.h>

int main() {
    char employeeID[10];
    float workHours, salaryRate;

    printf("Enter employee ID: ");
    gets(employeeID);

    printf("Enter work hours: ");
    scanf("%f", &workHours);

    printf("Salary (amount/hr): ");
    scanf("%f", &salaryRate);

    float totalSalary = salaryRate * workHours;

    printf("Employee ID: %s\n", employeeID);
    printf("Total Salary: %f\n", totalSalary);

    return 0;
}