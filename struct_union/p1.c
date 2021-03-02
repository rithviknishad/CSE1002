#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

typedef struct _Student
{
    int rollNumber, age;
    char *name, *address;
} Student;

void readStudentDetails(Student *student)
{
    printf("Student roll number : ");
    scanf("%d", &(student->rollNumber));

    static char _buffer[64];
    static int _bufferUsed;

    printf("Student name        : ");
    scanf("%s%n", _buffer, &_bufferUsed);

    student->name = malloc(sizeof(char) * _bufferUsed);
    strcpy(student->name, _buffer);

    printf("Student age         : ");
    scanf("%d", &(student->age));

    printf("Student address     : ");
    scanf("%s%n", _buffer, &_bufferUsed);

    student->address = malloc(sizeof(char) * _bufferUsed);
    strcpy(student->address, _buffer);

    printf("\n");
}

void printStudentDetails(const Student *student)
{
    printf("Student : {"
           "\n\t'Roll Number' : %d,"
           "\n\t'Name'        : '%s',"
           "\n\t'Age'         : %d,"
           "\n\t'Address'     : '%s',"
           "\n}\n",
           student->rollNumber, student->name, student->age, student->address);
}

/* 
    Iterator for [Student] starting from [head] to [n] elements, and invokes the [delegate] method.
    [argc] is the number of additional arguments that has to be forwarded on invocation of [delegate].
 */
void forEach(Student *head, int n, const void (*delegate)(Student *, va_list), int argc, ...)
{
    while (n--)
    {
        va_list additionalArgs;
        va_start(additionalArgs, argc);
        delegate(head++, additionalArgs);
        va_end(additionalArgs);
    }
}

void _internal_printNameIfAge14(const Student *student, ...)
{
    if (student->age == 14)
        printf("%s\n", student->name);
}

void _internal_printStudentIfRollNumberIsEven(const Student *student, ...)
{
    if (!(student->rollNumber % 2))
        printStudentDetails(student);
}

void _internal_printStudentIfRollNumberMatch(const Student *student, va_list args)
{
    // Extract the query from additional args received from the context of the parent iterator.
    int queryRollNumber = va_arg(args, int);
    int *hasMatchFlag = va_arg(args, int *);

    if (queryRollNumber == student->rollNumber)
    {
        *hasMatchFlag = 1;
        printStudentDetails(student);
    }
}

/* Prints the names of students whose [age] is 14. */
void printNamesWhereAge14(Student *students, int nStudents)
{
    printf("\n$ Students whose age is 14: \n");
    forEach(students, nStudents, _internal_printNameIfAge14, 0);
}

/* Prints the details of students whose roll number is even. */
void printDetailsWhereRollNumberIsEven(Student *students, int nStudents)
{
    printf("\n$ Students whose roll number is even: \n");
    forEach(students, nStudents, _internal_printStudentIfRollNumberIsEven, 0);
}

int main()
{
    int nStudents;

    printf("Number of students to enter: ");
    scanf("%d", &nStudents);

    Student *students = (Student *)malloc(sizeof(Student) * nStudents);

    for (int i = 0; i < nStudents; ++i)
        readStudentDetails(students + i);

    printNamesWhereAge14(students, nStudents);
    printDetailsWhereRollNumberIsEven(students, nStudents);

    int queryRollNumber, hasMatch = 0;

    printf("\n $ Enter a roll number to search: ");
    scanf("%d", &queryRollNumber);

    forEach(students, nStudents, _internal_printStudentIfRollNumberMatch, 1, queryRollNumber, &hasMatch);

    if (!hasMatch)
        printf("No match for roll number: %d\n", queryRollNumber);

    return 0;
}
