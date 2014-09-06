#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline);
void rstrip(char line[]);
int getLength(char s[]);
char isSpaceOrTab(char);

void main()
{
    char line[MAXLINE];
    int length;
    while(length = getLine(line, MAXLINE) > 0)
    {
        printf("input: %s", line);
        if (length == 0 && line[0] == '\n')
            continue;
        rstrip(line);
        printf(line);
    }
}

int getLine(char line[], int maxline)
{
    printf("input string\n");
    int currentChar, i;
    for (i = 0; i < maxline - 1 && (currentChar = getchar()) != EOF && currentChar != '\n'; ++i)
        line[i] = currentChar;
    if (currentChar == '\n')
    {
        line[i] = currentChar;
        ++i;
    }
    line[i] = '\0';
    return i;
}

void rstrip(char line[])
{
    int i;
    int lengthWithoutNewLine = getLength(line) - 1;
    for (i = lengthWithoutNewLine; i >= 0; --i)
    {
        char currentChar = line[i];
        if (isSpaceOrTab(currentChar))
        {
            // printf("the character '%c' is space or tab\n", currentChar);
            line[i] = '\n';
            line[i + 1] = '\0';
        }
        else
        {
            // printf("the character '%c' is not space or tab\n", currentChar);
            break;
        }
    }
}

int getLength(char s[])
{
    int i = 0;
    for (; s[i] != EOF && s[i] != '\n'; ++i)
        ;
    return i;
}

char isSpaceOrTab(char character)
{
    return (character == '\t' || character == ' ');
}
