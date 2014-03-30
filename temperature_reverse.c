#include <stdio.h>

main()
{
    int celsius, fahr;
    int lowerCelsius, upperCelsius, stepCelsius;

    lowerCelsius = 0;
    upperCelsius = 300;
    stepCelsius = 20;

    celsius = lowerCelsius;
    printf("%3s %4s\n", "C", "F");
    printf("==========\n");
    while(celsius <= upperCelsius) 
    {
        fahr = celsius/5*9 + 32;
        printf("%3d %4d\n", celsius, fahr);
        celsius = celsius + stepCelsius;
    }
}

