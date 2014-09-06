#include <stdio.h>
#define MAX 1000
#define FALSE 0
#define TRUE 1

char isOpeningPairChar(char c);
char isClosingPairChar(char c);
char getPair(char c);

char isInsideComment(char currentChar, char nextChar);
char isInsideString(char currentChar, char previousChar, char previousPreviousChar);

char opened[MAX];
int openedNum;

char insideMultilineComment;
char insideOnelineComment;
char insideSingleQuote;
char insideDoubleQuote;
char insideNotExecutable;

int main()
{
    insideMultilineComment = insideOnelineComment = FALSE;
    insideSingleQuote = insideDoubleQuote = FALSE;
    char previousPreviousChar, previousChar, currentChar, nextChar;
    previousChar = currentChar = nextChar = getchar();
    //previousChar = '\0';
    insideNotExecutable = FALSE;
    while((previousPreviousChar = previousChar) && (previousChar = currentChar) && ((currentChar = nextChar) != EOF))
    {
        nextChar = getchar();
        //printf("previousprevious char %c\tprevioius char: %c\tcurrent char: %c\tnext char: %c\n", previousPreviousChar, previousChar, currentChar, nextChar);
        if(isInsideString(currentChar, previousChar, previousPreviousChar) || isInsideComment(currentChar, nextChar))
        {
            insideNotExecutable = TRUE;
        }
        else
        {
            insideNotExecutable = FALSE;
            if(isOpeningPairChar(currentChar))
            {
                opened[++openedNum] = currentChar;
                continue;
            }
            if(isClosingPairChar(currentChar))
            {
                char pair = getPair(currentChar);
                if(openedNum > 0 && getPair(currentChar) == opened[openedNum])
                {
                    --openedNum;
                }
                else
                {
                    printf("not compensated\n");
                    return FALSE;
                }
            }
        }
    }
    if(openedNum == 0 && !insideNotExecutable)
    {
        printf("compensated\n");
        return TRUE;
    }
    else
    {
        printf("not compensated\n");
        return FALSE;
    }
}

char isOpeningPairChar(char c)
{
    return (c == '(' ||
            c == '[' ||
            c == '{');
}

char isClosingPairChar(char c)
{
    return (c == ')' ||
            c == ']' ||
            c == '}');
}

char getPair(char c)
{
    if(c == '(') return ')';
    if(c == ')') return '(';
    if(c == '{') return '}';
    if(c == '}') return '{';
    if(c == '[') return ']';
    if(c == ']') return '[';
    return c;
}

char isInsideComment(char currentChar, char nextChar)
{
    if(insideOnelineComment)
    {
        if(currentChar == '\n')
        {
            insideOnelineComment = FALSE;
        }
        return TRUE;
    }
    if(insideMultilineComment)
    {
        if(currentChar == '*')
        {
            if (nextChar == '/')
                insideMultilineComment = FALSE;
        }
        return TRUE;
    }
    if(currentChar == '/')
    {
        if (nextChar == '/')
            insideOnelineComment = TRUE;
        else if(nextChar == '*')
            insideMultilineComment = TRUE;
        else
        {
            return FALSE;
        }
        return TRUE;
    }
    return FALSE;
}

char isInsideString(char currentChar, char previousChar, char previousPreviousChar)
{
    char wasPreviousCharNotEscapedSlash = (previousChar == '\\' && previousPreviousChar != '\\');
    if(insideSingleQuote)
    {
        if(currentChar == '\'' && !wasPreviousCharNotEscapedSlash)
        {
            insideSingleQuote = FALSE;
        }
        //printf("inside string!\n");
        return TRUE;
    }
    if(insideDoubleQuote)
    {
        if(currentChar == '\"' && !wasPreviousCharNotEscapedSlash)
        {
            insideDoubleQuote = FALSE;
        }
        //printf("inside string!\n");
        return TRUE;
    }
    if(currentChar == '\'' && !wasPreviousCharNotEscapedSlash)
    {
        insideSingleQuote = TRUE;
        //printf("inside string!\n");
        return TRUE;
    }
    if(currentChar == '\"' && !wasPreviousCharNotEscapedSlash)
    {
        insideDoubleQuote = TRUE;
        //printf("inside string!\n");
        return TRUE;
    }
    //printf("NOT inside string!\n");
    return FALSE;
}
