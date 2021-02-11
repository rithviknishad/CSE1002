#include <stdio.h>

int main()
{
    int n;

    printf("Enter value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        int cube = i * i * i;
        printf("Number is: %d and cube is: %d\n", i, cube);
    }

    return 0;
}