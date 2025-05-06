#include <stdio.h>
#include <cs50.h>

// Inserting my meow function 'prototype' in order to hint the system to use the meow func. described further below, after 'main'
// BE AWARE!!! The firt line of the func., the so called prototype, MUST END WITH ; !!!
void meow(int n);
int prompt_for_times(void);

int main(void)
{
  int x = get_int("Insert a value for x: ");
  int y = get_int("Insert a value for y: ");
  
  printf("x = %i\n", x);
  printf("y = %i\n", y);

  if (x > y)
    printf("x (%i) > y (%i)\n", x, y);
  else if (x < y) 
    printf("x (%i) < y (%i)\n", x, y);
  else
    printf("x (%i) == y (%i)\n", x, y);

  char c = get_char("Do you Agree?: ");
  if(c == 'y' || c == 'Y')
    printf("Agreed!\n");
  else if(c == 'n' || c == 'N')
    printf("Not Agreed!\n");

  // Implementig a meow loop
  int i = 3;
  while (i > 0) {
    printf("Meeeooowww...\n");
    i--;
  }

  // Calling my meow functions
  int n = prompt_for_times();
  meow(n);
}

//Implementing the prompt_for_times function
int prompt_for_times(void)
{
  int times;
  do 
  {
    times = get_int("How many Meow do you want? ");
  } 
  while (times < 1);
  return times;
}

//Implementing the Meow function - as a convention the 'main' function should be on top, therefore I have to put my custom functions below main 
void meow(int n)
{
 for (int i=0; i < n; i++)
 printf("!!!Meeeooowww!!!\n");
}
