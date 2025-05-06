#include <stdio.h>
#include <cs50.h>

void division(void);

int main(void)
{
  int x = get_int("x value: ");
  int y = get_int("y value: ");
  //int op = get_string("chose your operator: ");
  int r = x + y;
  printf("your operation is:\n");
  printf("%i + %i\n", x, y);
  // 1st way
  printf("Result = %i\n",r);
  // 2nd way
  printf("Result 2 = %i\n", x + y);
  //a 3rd way
  printf("Result 3 = %i\n", get_int("x: ") + get_int("y: "));

  //Simple "DOUBLE IT" IMPLEMENTATION
  printf("'DOUBLE-IT' result: %i\n", x * 2);

  //Implementation of the DOLLAR-EXPONENTIAL-MOLTIPLICATOR INTEGER OVERFLOW GIVEN TO THE 32BIT LIMIT
  long dollars = 1;
  while (true) {
    char q = get_char("Here's %li $. Double it and give it to the next person? ", dollars);
      if (q == 'y') {
          dollars *= 2;
      }
      else if (q == 'n') {
        break;
      }
  }
  printf("Now you've got a total of %li $ in your pokets!\n", dollars);

  division();

}

//Implementing Divisions & FLOATING POINT IMPRECISION!
void division(void)
{
  int x = get_int("x: ");
  int y = get_int("y: ");

  printf("%i / %i = %.50f\n", x, y, (float) x / y);
}

