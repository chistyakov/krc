#include <stdio.h>

#define TABLENGTH 4
#define TRUE 1
#define FALSE 0
#define MAXLENGTH 1000

void detab(char s[]);
int getLength(char s[]);

int main()
{
    char currentChar;
    char spacesOnly = TRUE;
    char lineBuffer[MAXLENGTH];
    int charsInLineCounter = 0;
    while ((currentChar = getchar()) != EOF &&
           (charsInLineCounter < MAXLENGTH))
    {
        if (!(currentChar == ' ' || currentChar == '\n'))
            spacesOnly = FALSE;
        if (spacesOnly == TRUE)
        {
            lineBuffer[charsInLineCounter++] = currentChar;
        }
        if (currentChar == '\n')
        {
            if (spacesOnly == TRUE)
            {
                //lineBuffer[charsInLineCounter + 1] = '\0';
                detab(lineBuffer);
                printf(lineBuffer);
            }
            spacesOnly = TRUE;
            charsInLineCounter = 0;
        }
    }
    return 0;
}

void detab(char s[])
{
    int i = 0;
    int length = getLength(s);
    printf("length: %d", length);
    int tabsNumber = length / TABLENGTH;
    int spacesNumber = length % TABLENGTH;
    printf("tabs: %d spaces: %d\n", tabsNumber, spacesNumber);
    for (; i < tabsNumber; ++i)
        s[i] = '\t';
    for (; i < tabsNumber + spacesNumber; ++i)
        s[i] = ' ';
    s[i] = '\n';
    s[++i] = '\0';
}

int getLength(char s[])
{
    int i = 0;
    for (; s[i] != EOF && s[i] != '\n'; ++i)
        ;
    return i;
}
