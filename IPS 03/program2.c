#include <stdio.h>

#define TRIANGLE_SIDES 3

int isEquilateral(float *sides)
{
    return (sides[0] == sides[1] && sides[1] == sides[2]);
}

int isIsosceles(float *sides)
{
    return (sides[0] == sides[1] || sides[1] == sides[2] || sides[0] == sides[2]);
}

int main()
{
    float sides[TRIANGLE_SIDES];

    for (int i = 0; i < TRIANGLE_SIDES; ++i)
    {
        printf("Enter side %d length: ", i);
        scanf("%f", sides + i);
    }

    if (isEquilateral(sides))
        printf("Equilateral Triangle");
    else if (isIsosceles(sides))
        printf("Isosceles Triangle");
    else
        printf("Scalene Triangle");

    return 0;
}