 #include <stdio.h>

#define MAX_CHAR 257 

main()
{
    int countOfChars[MAX_CHAR];
    int currentChar;
    int i;
    for(i = 0; i < MAX_CHAR; ++i)
        countOfChars[i] = 0;
    while((currentChar = getchar()) != EOF)
    {
        if(currentChar < MAX_CHAR)
            ++countOfChars[currentChar];
        else
            ++countOfChars[MAX_CHAR];
    }

    int maxCountOfChars = 0;
    for(i = 0; i < MAX_CHAR; ++i)
    {
        if(countOfChars[i] > maxCountOfChars)
            maxCountOfChars= countOfChars[i];
    }

    int y, x;
    for(y = maxCountOfChars; y > 0 ; --y)
    {
        printf("%3d|", y);
        for(x = 0; x < MAX_CHAR; ++x)
        {
            if(countOfChars[x] != 0)
            {
                if(countOfChars[x] >= y)
                    printf("%2c", '*');
                else
                    printf("%2c", ' ');
            }
        }
        putchar('\n');
    }
    printf("    ");
    for(x = 0; x < MAX_CHAR; ++x)
    {
        if(countOfChars[x] != 0)
            printf("==");
    }
    putchar('\n');
    printf("    ");
    for(x = 0; x < MAX_CHAR; ++x)
    {
        if(countOfChars[x] != 0)
        {
            if(x == '\n')
                printf("\\n");
            else if(x == '\t')
                printf("\\t");
            else if(x == ' ')
                printf("%2c", '_');
            else
                printf("%2c", x);
        }
    }
    putchar('\n');
}
