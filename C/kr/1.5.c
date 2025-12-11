#include <stdio.h>

int main()
{
    printf("1.5: Fahrenheit-Celsius Conversion Table - for and reversed\n\n");
    
    int fa;
    /* using symbolic constants in order to avoid 'magic numbers' */
    #define START 300
    #define END 0 
    #define STEP 1 

    for (fa = START; fa >= END; fa = fa - STEP)
    {
        printf("%6d %6.2f\n", fa, (5.00/9.00) * (fa - 32.00));
    }
    
}
