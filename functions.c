#include <stdio.h>
#include <math.h>

void readCount(int *, int);
float findMean(int *, int);
void printDiff(int *, int, float);

int main()
{
    int accDetails[20], nDays, ctr;
    float mean;

    scanf("%d", &nDays);
    readCount(accDetails, nDays);

    mean = findMean(accDetails, nDays);
    printf("%f\n", mean);
    printDiff(accDetails, nDays, mean);

    return 0;
}

void readCount(int *acc, int num)
{
    int ctr = 0;
    while (ctr < num)
        scanf("%d", &acc[ctr++]);
}

float findMean(int *acc, int num)
{
    int total = 0, ctr = 0;

    while (ctr < num)
        total += acc[ctr++];

    return (float)total / num;
}

void printDiff(int *acc, int num, float mean)
{
    int ctr = 0;
    while (ctr < num)
        printf("%d\n", (int)round(fabsf(mean - acc[ctr++])));
}
