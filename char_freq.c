#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string[20];
    int freq[26] = {0}, ctr;

    scanf("%[^\n]s", string);

    for (ctr = 0; ctr < strlen(string); ++ctr)
    {
        if (isalpha(string[ctr]))
            freq[tolower(string[ctr]) - 'a']++;
    }

    for (ctr = 0; ctr < 26; ++ctr)
        printf("%c\t%d\n", 'a' + ctr, freq[ctr]);

    return 1;
}