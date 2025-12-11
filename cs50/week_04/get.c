//#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    /* int n; 
    printf("Chose your int: ");
    scanf("%i", &n);
    printf("You chose %i, well done!\n", n);
    */
    char *s = malloc(32);
    printf("chose a string: ");
    fgets(s, 32, stdin);
    printf("your string is: %s\n", s);
    free(s);
    return 0;
}
