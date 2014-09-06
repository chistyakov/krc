#include <stdio.h>
#define MAXLENGTH 10

char isBlank(char character);
void substring(char from[], char to[], int startIndex, int stopIndex);

void main()
{
    char currentChar;
    int MAXINDEXINLINE = MAXLENGTH - 1;
    int newlineInsertionIndex = MAXINDEXINLINE;
    int i = 0;
    char currentLine[MAXLENGTH];
    char subline[MAXLENGTH];
    while ((currentChar = getchar()) != EOF)
    {
        currentLine[i] = currentChar;
        if (isBlank(currentChar))
            newlineInsertionIndex = i;
        if (currentChar == '\n')
        {
            currentLine[i + 1] = '\0';
            printf(currentLine);
            i = 0;
            newlineInsertionIndex = MAXINDEXINLINE;
            continue;
        }
        if (i == MAXINDEXINLINE)
        {
            substring(currentLine, subline, 0, newlineInsertionIndex);
            printf(subline);
            putchar('\n');
            substring(currentLine, currentLine, newlineInsertionIndex + 1, MAXLENGTH);
            i = MAXINDEXINLINE - newlineInsertionIndex;
            newlineInsertionIndex = MAXINDEXINLINE;
            continue;
        }
        ++i;
    }
}

char isBlank(char character)
{
    return (character == '\t' || character == ' ');
}

void substring(char from[], char to[], int startIndex, int stopIndex)
{
    int i;
    for (i = startIndex; i < stopIndex; ++i)
        to[i - startIndex] = from[i];
    to[i-startIndex] = '\0';
}
