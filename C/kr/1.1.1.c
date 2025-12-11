#include <stdio.h>

/* Print Fahrenheit-Celsius table
   for fahr = 0, 20..., 300 */

int main(void) {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
  
    printf("\n\nFahrenheit-to-Celsius conversion table\n\n");

    // The conversion formula is: °C = (5/9)*(°F-32) 
    
    while (fahr <= upper) {
        celsius = (fahr - 32.0) * 5.0 / 9.0;
        printf("%3.0f\t%5.1f\n", fahr, celsius);
        fahr += step;
    }
}
