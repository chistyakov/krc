#include <stdio.h>

float convertFahrToCelsius(int fahr);

main()
{
    int fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    printf("%3s %6s\n", "F", "C");
    printf("==========\n");
    for(fahr = upper; fahr >= lower; fahr = fahr - step)
    {
        printf("%3d %6.1f\n", fahr, convertFahrToCelsius(fahr));
    }
}

float convertFahrToCelsius(int fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}
