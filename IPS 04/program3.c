#include <stdio.h>
#include <math.h>

double fact(double n)
{
    return (n == 1) ? 1 : (n * fact(n - 1));
}

double f(double x, int i, int limit)
{
    if (i == 0)
        return 1;

    if (i == limit - 1)
        return 0;

    return ((i % 4 ? 1 : -1) * pow(x, i) / fact(i)) + f(x, i + 2, limit);
}

int main()
{
    int x, i;

    printf("Enter value of x: ");
    scanf("%d", &x);

    printf("Enter number of terms: ");
    scanf("%d", &i);

    double result = f(x, 0, i);

    printf("sum: %f", result);

    return 0;
}