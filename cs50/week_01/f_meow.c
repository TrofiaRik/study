#include <stdio.h>
#include <cs50.h>

//Here the functions prototyps
int get_times_positive(void);
void print_meow_n_times(int n);

//Here the main func
int main(void)
{
  int n = get_times_positive();
  print_meow_n_times(n);
}

//Here the get_times_positive function 
int get_times_positive(void)
{
  int pt;
  do 
  {
    pt = get_int("How many meow do you whish? ");
  } 
  while (pt < 1);
  return pt;
}

//Here the print_meow_n_times
void print_meow_n_times(int n)
{
  for (int i=0; i < n; i++) 
  printf("!!!Meeeooowww!!!\n");
}

