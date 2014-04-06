#include <stdio.h>
#define MAXLINE 1000
#define TRUE 1
#define FALSE 0

int getLineAndLineLength(char line[], int maxLengthline);
void copy(char to[], char from[]);

main()
{
    char line[MAXLINE];
    char firstFragmentOfLine[MAXLINE];
    char longest[MAXLINE];

    int maxLength = 0;
    int currentLength = 0;
    int currentFragmentLength;
    char isCurrentFragmentFirst = TRUE;
    while((currentFragmentLength = getLineAndLineLength(line, MAXLINE)) > 0)
    {
        if(isCurrentFragmentFirst)
            copy(firstFragmentOfLine, line);
        currentLength = currentLength + currentFragmentLength;
        if(currentLength > maxLength)
        {
            maxLength = currentLength;
            copy(longest, firstFragmentOfLine);
        }
        if((MAXLINE-1) == currentFragmentLength && '\n' != line[currentFragmentLength - 1])
        {
            isCurrentFragmentFirst = FALSE;
            continue;
        }
        isCurrentFragmentFirst = TRUE;
        currentLength = 0;
    }
    if(maxLength > 0)
    {
        printf("max length: %d\n", maxLength);
        printf("line: %s", longest);
    }
    return 0;
}

int getLineAndLineLength(char s[], int lim)
{
    int c, i;

    for(i = 0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
        s[i] = c;
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}


