#include <stdio.h>

int main()
{
    int n, sum = 0;

    printf("Enter value of n: ");
    scanf("%d", &n);

    printf("The positive disors: ");

    for (int i = 1; i < n; ++i)
    {
        if (!(n % i))
        {
            sum += i;
            printf("%d", i);
        }
    }

    if (sum == n)
        printf("\nNumber: %d is perfect number", n);
    else
        printf("\nNumber: %d is not a perfect number", n);

    return 0;
}