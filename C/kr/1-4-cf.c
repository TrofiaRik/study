#include <stdio.h>

/* Print Celsius-Fahrenheit table
   for fahr = 0, 20..., 300 */

int main(void) {
    
    int lower = -20;
    int upper = 150;
    int step = 1;
    float fahr;
    int celsius = lower;
  
    printf("\n\nCelsius-to-Fahrenheit conversion table\n\n");

    // The conversion formula is: °F = C * (9/5) + 32 
    
    while (celsius <= upper) {
        fahr = celsius * (9.0 / 5.0) + 32;
        printf("%3.0i\t%5.1f\n", celsius, fahr);
        celsius += step;
    }
}
