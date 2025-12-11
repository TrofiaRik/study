#include <stdio.h>

main()
{
    printf("Celsius-Fahrenheit Conversion Table\n\n");
    
    float fa, ce;
    float lower, upper, step;
    
    lower = -20.00;  /* lower limit of temp scale */
    upper = 250.00;  /* upper limit of temp scale */
    step = 1.00;        /* increment step aize */
    
    ce = lower;
    while (ce <= upper) {
        fa = (ce * 9.00/5.00) + 32.00;
        printf("%6.2f %6.2f\n", ce, fa);
        ce += step;
    }
}