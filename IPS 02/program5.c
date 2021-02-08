#include <stdio.h>

int main() {
    float totalDistance;
    float spentFuel;

    printf("Enter total distance (km): ");
    scanf("%f", &totalDistance);

    printf("Total fuel spent (litres): ");
    scanf("%f", &spentFuel);

    float avgConsumption = totalDistance / spentFuel;

    printf("Average consumption: %f km/litre\n", avgConsumption);

    return 0;
}