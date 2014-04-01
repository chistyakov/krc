#include <stdio.h>

main()
{
    int currentChar, previousChar = EOF;
    while((currentChar = getchar()) != EOF)
    {
        if(currentChar == ' ' ||
           currentChar == '\t' ||
           currentChar == '\n')
        {
            if(previousChar == ' ' ||
               previousChar == '\t' ||
               previousChar == '\n')
                continue;
            putchar('\n');
        }
        else
            putchar(currentChar);
        previousChar = currentChar;
    }
}

