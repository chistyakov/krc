#include <stdio.h>

main()
{
    int currentChar;
    while((currentChar = getchar()) != EOF)
    {
        if(currentChar == '\t')
        {
            putchar('\\');
            putchar('t');
            continue;
        }
        if(currentChar == '\b')
        {
            putchar('\\');
            putchar('b');
            continue;
        }
        if(currentChar == '\\')
        {
            putchar('\\');
            putchar('\\');
            continue;
        }
        putchar(currentChar);
    }
}
