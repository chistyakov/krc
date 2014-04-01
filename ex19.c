#include <stdio.h>

#define TRUE 1
#define FALSE 0

main()
{
    int currentChar;
    int totalFollowingSpaces = 0;
    char lineHasOnlySpaces = TRUE;
    while((currentChar = getchar()) != EOF)
    {
        if(currentChar == ' ')
        {
            ++totalFollowingSpaces;
            continue;
        }
        if(currentChar == '\n')
        {
            if(lineHasOnlySpaces & totalFollowingSpaces > 0)
            {
                putchar(' ');
                totalFollowingSpaces = 0;
                continue;
            }
            lineHasOnlySpaces = TRUE;
        }
        else
            lineHasOnlySpaces = FALSE;
        int i;
        for(i = 0; i < totalFollowingSpaces; ++i)
            putchar(' ');
        putchar(currentChar);

        totalFollowingSpaces = 0;
    }
}

