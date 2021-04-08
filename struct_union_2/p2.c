#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int age;
    float height, chest;
} Trainee;

void readTraineeDetails(Trainee *trainee)
{
    static char _buffer[64];
    static int _bufferUsed;

    printf("Trainee name        : ");
    scanf("%s%n", _buffer, &_bufferUsed);

    trainee->name = malloc(sizeof(char) * _bufferUsed);
    strcpy(trainee->name, _buffer);

    printf("Age                 : ");
    scanf("%d", &(trainee->age));

    printf("Height (inches)     : ");
    scanf("%f", &(trainee->height));

    printf("Chest (cm)          : ");
    scanf("%f", &(trainee->chest));

    printf("\n");
}

int isFit(const Trainee *trainee)
{
    return (5.2 <= trainee->height && trainee->height <= 5.6) && (18 <= trainee->age && trainee->age <= 25) && (trainee->chest >= 45);
}

void printFitenessReport(const Trainee *trainee)
{
    char *status = isFit(trainee) ? "FIT" : "NOT FIT";
    printf("`%s` of age `%d` is %s\n",
           trainee->name, trainee->age, status);
}

void forEach(Trainee *head, int n, const void (*delegate)(Trainee *))
{
    while (n--)
        delegate(head++);
}

void main()
{
    int nTrainees;

    printf("Number of trainees to enter: ");
    scanf("%d", &nTrainees);

    Trainee *trainees = (Trainee *)malloc(sizeof(Trainee) * nTrainees);

    forEach(trainees, nTrainees, readTraineeDetails);
    forEach(trainees, nTrainees, printFitenessReport);
}