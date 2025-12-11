#include <stdio.h>

/* Print Celsius-Fahrenheit table
   INVERTED and using FOR - for fahr = 0, 20..., 300 */

int main(void) {
  
  // Declearing Symbolic constants in order to avoid variables declarations or magic numbers 
  #define LOWER  300
  #define UPPER  0
  #define STEP  20
  
    printf("\n\nFahrenheit-to-Celsius-Inverted conversion table\n\n");

    // The conversion formula is: °C = (5/9)*(°F-32) 
    for (int fahr = LOWER; fahr >= UPPER; fahr -= STEP)
    {
        printf("%3i\t%5.1f\n", fahr, (5.0 / 9.0) * (fahr + 32));
    }
}
