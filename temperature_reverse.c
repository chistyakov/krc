#include <stdio.h>

main()
{
    float fahr;
    int celsius;
    int lowerCelsius, upperCelsius, stepCelsius;

    lowerCelsius = 0;
    upperCelsius = 300;
    stepCelsius = 20;

    celsius = lowerCelsius;
    printf("%3s %6s\n", "C", "F");
    printf("==========\n");
    while(celsius <= upperCelsius) 
    {
        fahr = (9.0/5.0)*celsius + 32.0;
        printf("%3d %6.1f\n", celsius, fahr);
        celsius = celsius + stepCelsius;
    }
}

