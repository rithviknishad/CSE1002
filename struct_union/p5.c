#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct
{
    int day, month, year;
} Date;

int isLeapYear(int year)
{
    return (!(year % 4) && (year % 100) || !(year % 400));
}

long daysSinceEpoch(const Date date)
{
    int days = date.day;

    for (int y = 1970; y < date.year; ++y)
        days += isLeapYear(y) ? 366 : 365;

    switch (date.month - 1)
    {
    case 11:
        days += 30;
    case 10:
        days += 31;
    case 9:
        days += 30;
    case 8:
        days += 31;
    case 7:
        days += 31;
    case 6:
        days += 30;
    case 5:
        days += 31;
    case 4:
        days += 30;
    case 3:
        days += 31;
    case 2:
        days += isLeapYear(date.year) ? 29 : 28;
    case 1:
        days += 31;
    }

    return days + 1;
}

Date dateFromDaysSinceEpoch(long remainingDays)
{
    Date result = {1, 1, 1970}; // 1st January, 1970 -> (Epoch)

    while (remainingDays >= (isLeapYear(result.year + 1) ? 366 : 365))
        remainingDays -= isLeapYear(++result.year) ? 366 : 365;

    int daysInMonth[] = {31, isLeapYear(result.year) ? 29 : 30,
                         31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while (remainingDays >= daysInMonth[result.month + 1])
        remainingDays -= daysInMonth[++result.month];

    result.day += remainingDays;

    return result;
}

void main()
{
    Date date;

    printf("Input Date (format: dd/mm/yyyy): ");
    scanf("%d/%d/%d", &(date.day), &(date.month), &(date.year));

    int _daysToAdd;
    printf("Days to add: ");
    scanf("%d", &_daysToAdd);

    Date result = dateFromDaysSinceEpoch(daysSinceEpoch(date) + _daysToAdd);

    printf("Result: %d/%d/%d", result.day, result.month, result.year);
}