#include <stdio.h>

int years(int days) {
    return days / 365;
}

int weeks(int days) {
    return (days % 365) / 7;
}

int main() {
    int inputDays;

    printf("Enter days: ");
    scanf("%d", &inputDays);

    int y = years(inputDays);
    int w = weeks(inputDays);
    int d = inputDays % 7;

    printf("%d years %d weeks %d days\n", y, w, d);

    return 0;
}