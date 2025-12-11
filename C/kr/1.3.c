#include <stdio.h>

main()
{
    printf("Fahrenheit-Celsius Conversion Table\n\n");
    
    float fa, ce;
    float lower, upper, step;
    
    lower = 0.00;    /* lower limit of temp scale */
    upper = 451.00;  /* upper limit of temp scale */
    step = 1;    /* increment step aize */
    
    fa = lower;
    while (fa <= upper) {
        ce = (5.00/9.00) * (fa - 32.00);
        printf("%3.0f %6.2f\n", fa, ce);
        fa += step;
    }
}