#include <stdio.h>

main()
{
    int fahr;
    float celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%3s %6s\n", "F", "C");
    printf("==========\n");
    for(fahr = upper; fahr >= lower; fahr = fahr - step)
    {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%3d %6.1f\n", fahr, celsius);
    }
}

