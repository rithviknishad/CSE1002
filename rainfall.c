#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Date
{
    int date, month, year;
} Date;

typedef struct _RainfallRecord
{
    /* The date of record of this rainfall record instance. */
    Date date;

    /* Rainfall recorded for [date], [month], [year] in centimeters. */
    float rainfall_cm;

} RainfallRecord;

typedef struct _City
{
    /* City name of the instance */
    char *name;

    /* The number of records that can be accessed using [rainfalls]. */
    int nRecords;

    /* Pointer to all the records. */
    RainfallRecord *rainfalls;

    RainfallRecord *monthlyAverageRainfall;
    RainfallRecord *monthlyTotalRainfall;

} City;

void computeOutputs(City *city)
{
}

void inputRecord(RainfallRecord *record)
{
    printf("Date (input format: dd/mm/yyyy): ");
    scanf("%d/%d/%d", &(record->date.date), &(record->date.month), &(record->date.year));

    printf("Rainfall on the above mentioned date (cm): ");
    scanf("%f", &(record->rainfall_cm));
}

void inputCity(City *city)
{
    printf("City name: ");

    char _cityName[20];
    int _cityNameLength;

    scanf("%s%n", _cityName, &_cityNameLength);

    city->name = malloc(sizeof(char) * _cityNameLength);
    strcpy(city->name, _cityName);

    printf("No. of records for %s", city->name);
    scanf("%d", &(city->nRecords));

    city->rainfalls = malloc(city->nRecords * sizeof(RainfallRecord));

    printf("Enter rainfall records (chronologic order)");

    for (int i = 0; i < city->nRecords; ++i)
        inputRecord(city->rainfalls + i);
}

// TODO: also use year later on
void totalRainfall(City *city)
{
    for (int i = 1; i <= 12; ++i)
    {
    }
}

int main()
{
    int nCities;

    printf("Number of cities to record: ");
    scanf("%d", &nCities);

    City *cities = malloc(nCities * sizeof(City));

    for (int i = 0; i < nCities; ++i)
        inputCity(cities + i);

    return 0;
}