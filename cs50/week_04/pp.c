#include <stdio.h>

int main(void)
{
  int x = 4;
  int *p = &x;
  printf("## 1 ## val inside x = %i\n", x);
  printf("## 2 ## calling p as a pointer (using *, frabbing the address inside pointer) = %i\n", *p);
  printf("## 3 ## val inside p = %p\n", p);
  printf("## 4 ## address of x (&x) = %p\n", &x);
  printf("## 5 ## address of p = %p\n", &p);
  *p = 2;
  printf("changing and printing new x, via p = %i\n", *p);
  printf("changing and printing new x, via x = %i\n", x);


}
