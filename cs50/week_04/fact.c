#include <stdio.h>

long long fact(long long n);

int main(void)
{  
    int n;
    printf("Calculate the value of factorial 1-20: ");
    //scanf("%2d", &n);
    if (scanf("%d", &n) != 1) {
      printf("Wrong type!\n");
      return 1;
    }
  

    if (n < 0 || n > 20) {
      printf("Max input is 20!\n");
      return 1;
    }
    printf("Factorial of %d is: %llu\n", n, fact(n));
}

long long fact(long long n)
{
    if (n == 1)
      return 1;
    else
      return n * fact(n-1); 
}
