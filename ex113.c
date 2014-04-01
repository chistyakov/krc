 #include <stdio.h>

#define MAX_WORD_LENGTN 20

main()
{
    int countOfWordsPerLength[MAX_WORD_LENGTN];
    int currentWordLength = 0;
    int currentChar;
    int i;
    for(i = 0; i < MAX_WORD_LENGTN; ++i)
        countOfWordsPerLength[i] = 0;
    while((currentChar = getchar()) != EOF)
    {
        if(currentChar == ' ' ||
           currentChar == '\t' ||
           currentChar == '\n')
        {
            if(currentWordLength > 0)
                ++countOfWordsPerLength[currentWordLength - 1];
            currentWordLength = 0;
            continue;
        }
        if(currentWordLength < MAX_WORD_LENGTN)
            ++currentWordLength;
    }
    /* print a chart */
    int wordLength, countOfWordsWithCurrentLength;
    for(wordLength = 1; wordLength <= MAX_WORD_LENGTN; ++wordLength)
    {
        countOfWordsWithCurrentLength = countOfWordsPerLength[wordLength - 1];
        if(wordLength == MAX_WORD_LENGTN)
            printf(">%2d (%3d) |", wordLength - 1, countOfWordsWithCurrentLength);
        else 
            printf("%3d (%3d) |", wordLength, countOfWordsWithCurrentLength);
        int j;
        for(j = 0; j < countOfWordsWithCurrentLength; ++j)
            putchar('=');
        putchar('\n');
    }

    int maxCountOfWords = 0;
    for(i = 0; i < MAX_WORD_LENGTN; ++i)
    {
        if(countOfWordsPerLength[i] > maxCountOfWords)
            maxCountOfWords = countOfWordsPerLength[i];
    }

    int y, x;
    for(y = maxCountOfWords; y > 0 ; --y)
    {
        for(x = 0; x < MAX_WORD_LENGTN; ++x)
        {
            if(countOfWordsPerLength[x] >= y)
                printf("%3c", '*');
            else
                printf("%3c", ' ');
        }
        putchar('\n');
    }
    for(x = 0; x < MAX_WORD_LENGTN; ++x)
        printf("===");
    putchar('\n');
    for(x = 0; x < MAX_WORD_LENGTN; ++x)
        printf("%3d", countOfWordsPerLength[x]);
    putchar('\n');
    for(x = 0; x < MAX_WORD_LENGTN; ++x)
        printf("---");
    putchar('\n');
    for(wordLength = 1; wordLength < MAX_WORD_LENGTN; ++wordLength)
        printf("%3d", wordLength);
    printf(">%2d", wordLength - 1);
    putchar('\n');
}
