#include <stdio.h>
#define MAXLINE 1000

void reversed(char s[]);
int getLength(char s[]);
void swapLetters(char s[], int index1, int index2);
int getLine(char line[], int maxline);

void main()
{
    printf("reverse strings\n");
    char line[MAXLINE];
    int len;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        printf("input: %s", line);
        reversed(line);
        printf("reversed: %s", line);
    }
}

int getLine(char line[], int maxline)
{
    printf("input string to reverse\n");
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

void reversed(char s[])
{
    int slen = getLength(s);
    int i = 0;
    for(; i<slen/2; ++i)
    {
        swapLetters(s, i, slen - i - 1);
    }
}

int getLength(char s[])
{
    int i = 0;
    for (; s[i] != EOF && s[i] != '\n'; ++i)
        ;
    return i;
}

void swapLetters(char s[], int index1, int index2)
{
    char bubble = s[index1];
    s[index1] = s[index2];
    s[index2] = bubble;
}
