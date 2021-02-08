#include <stdio.h>
#include <math.h>

float perimeter(float radius) {
    return 2 * M_PI * radius;
}

float area(float radius) {
    return M_PI * radius * radius;
}

int main() {
    float radius;

    printf("Enter radius (inches): ");
    scanf("%f", &radius);

    float p = perimeter(radius);
    float a = area(radius);

    printf("Perimeter: %f inches\n", p);
    printf("Area: %f inches^2\n", a);

    return 0;
}