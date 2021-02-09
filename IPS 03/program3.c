#include <stdio.h>

int main()
{
    char input;

    printf("Enter character to check: ");
    scanf("%c", &input);

    if ('0' <= input && input <= '9')
        printf("Numeric");
    else if (('a' <= input && input <= 'z') || ('A' <= input && input <= 'Z'))
        printf("Alphabet");
    else
        printf("Special character");

    return 0;
}