#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name[20];
    int population;
    float literacyRate, income;

} State;

void readState(State *state)
{
    scanf("%s %d %f %f", state->name, &(state->population), &(state->literacyRate), &(state->income));
}

void main()
{
    int nStates;
    scanf("%d", &nStates); // Input number of states to be entered
    State *states = malloc(sizeof(State) * nStates);

    // result pointers points to 1st element by default
    State *highestLiteracyRateState = states, *highestIncomeState = states;

    for (int i = 0; i < nStates; ++i)
    {
        State *state = states + i;
        readState(state);

        // using i also in condition to skip unnecessary checks and assignments for first element
        if (i && state->income > highestIncomeState->income)
            highestIncomeState = state;

        if (i && state->literacyRate > highestLiteracyRateState->literacyRate)
            highestLiteracyRateState = state;
    }

    printf("%s\n%s", highestLiteracyRateState->name, highestIncomeState->name);
}