#include <stdio.h>

struct rainfallPacket
{
    int day;
    int month;
    int rainfall;
};

int sum(int *arr, int n)
{
    int total = 0;

    while (n)
        total += arr[--n];

    return total;
}

float findMean(int *arr, int n)
{
    return (float)sum(arr, n) / n;
}

int main()
{

    int days, arr[20];

    scanf("%d", &days);

    for (int i = 0; i < days; ++i)
        scanf("%d", &arr[i]);

    printf("Total rainfall: %d cm\n", sum(arr, days));
    printf("Average: %f cm\n", findMean(arr, days));

    return 0;
}