#include <stdio.h>

int main()
{
    int n, sum = 0;

    printf("Enter value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        printf("%d ", i);
        sum += i;
    }

    printf("\nThe Sum of Natural Numbers up to %d terms: %d\n", n, sum);

    return 0;
}