#include <stdio.h>

int main()
{
    float temp;

    printf("Enter temperature (C): ");
    scanf("%f", &temp);

    if (temp < 0.0)
        printf("Freezing Weather!");
    else if (temp <= 10.0)
        printf("Very cold Weather.");
    else if (temp <= 20.0)
        printf("Cold Weather.");
    else if (temp <= 30.0)
        printf("Normal temperature.");
    else if (temp <= 40.0)
        printf("Hot weather.");
    else
        printf("Very hot Weather!");

    return 0;
}