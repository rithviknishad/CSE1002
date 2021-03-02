#include <stdio.h>
#include <string.h>

typedef struct
{
    int day, month, year;
} Date;

int isEqual(const Date a, const Date b)
{
    return (a.day == b.day && a.month == b.month && a.year == b.year);
}

void readDate(Date *date, const char *prefix)
{
    printf("%s", prefix);
    scanf("%d/%d/%d", &(date->day), &(date->month), &(date->year));
}

void main()
{
    Date date1, date2;

    readDate(&date1, "Input Date 1 (format: dd/mm/yyyy): ");
    readDate(&date2, "Input Date 2 (format: dd/mm/yyyy): ");

    printf("Dates are %s", isEqual(date1, date2) ? "equal" : "not equal");
}