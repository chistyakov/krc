#include <stdio.h>

main()
{
    int totalSpaces = 0;
    int totalTabs = 0;
    int totalNewLines = 0;

    int currentChar;
    while((currentChar = getchar()) != EOF)
    {
        if(currentChar == ' ')
            ++totalSpaces;
        if(currentChar == '\t')
            ++totalTabs;
        if(currentChar == '\n')
            ++totalNewLines;
    }
    printf("spaces: %d\ntabs: %d\nnew lines: %d",
            totalSpaces,
            totalTabs,
            totalNewLines);
}

