#include <stdio.h>
#define TABLENGTH 4

void putSpaces(int numberOfSpaces);

void main()
{
    char currentChar;
    int charsSinceTabstop;
    for (charsSinceTabstop = 0; (currentChar = getchar()) != EOF; ++charsSinceTabstop)
    {
        if (currentChar == '\t')
        {
            int numSpacesToPrint = TABLENGTH - ((charsSinceTabstop - 1) % TABLENGTH);
            putSpaces(numSpacesToPrint);
            continue;
        }
        if (currentChar == '\n')
            charsSinceTabstop = 0;
        putchar(currentChar);
    }
}

void putSpaces(int numberOfSpaces)
{
    int i;
    for (i = 0; i < numberOfSpaces; ++i)
        putchar(' ');
}
