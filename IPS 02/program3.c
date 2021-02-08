#include <stdio.h>

int main() {
    float w1, q1, w2, q2;

    printf("Item 1 Weight: ");
    scanf("%f", &w1);
    
    printf("Item 1 Qty: ");
    scanf("%f", &q1);

    printf("Item 2 Weight: ");
    scanf("%f", &w2);

    printf("Item 2 Qty: ");
    scanf("%f", &q2);

    float totalQuantity = q1 + q2;
    float average = ((w1 * q1) + (w2 * q2)) / totalQuantity;

    printf("Average value: %f\n", average);

    return 0;
}