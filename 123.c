#define TRUE 1
#define FALSE 0
#include <stdio.h>

void main()
{
    char insideMultilineComment;
    char insideOnelineComment;
    insideMultilineComment = insideOnelineComment = FALSE;
    char currentChar;
    while((currentChar = getchar()) != EOF)
    {
        if(insideOnelineComment)
        {
            if(currentChar == '\n')
            {
                insideOnelineComment = FALSE;
                putchar(currentChar);
            }
            continue;
        }
        if(insideMultilineComment)
        {
            if(currentChar == '*')
            {
                char nextChar = getchar();
                if (nextChar == '/')
                    insideMultilineComment = FALSE;
            }
            continue;
        }
        if(currentChar == '/')
        {
            char nextChar = getchar();
            if (nextChar == '/')
                insideOnelineComment = TRUE;
            else if(nextChar == '*')
                insideMultilineComment = TRUE;
            else
            {
                putchar(currentChar);
                putchar(nextChar);
            }
            continue;
        }
        putchar(currentChar);
    }
}
