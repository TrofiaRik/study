#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n = 50;
  
    int *p = &n;
    int *u = &n;

    string s = "HI!";

    printf("Address of the string array:");
    printf("%p\n\n", s);
    
    printf("Address of the first element of the array = 1st character:");
    printf("%p\n\n", &s[0]);

    printf("Stampa l'indirizzo della variabile 'n'\n");
    printf("%p\n\n", &n);
    
    printf("Stampa l'indirizzo memorizzato nel pointer *p\n");
    printf("%p\n", (void *)p);
    printf("Stampa l'indirizzo memorizzato nel pointer *u\n");
    printf("%p\n\n", (void *)u);

    printf("Stampa l'indirizzo degli stessi pointers\n");
    printf("%p\n\n", (void *)&p);
    printf("%p\n\n", (void *)&u);
    
    printf("Stampa il valore collegato ai pointers\n");
    printf("%i\n", *p);
    printf("%i\n", *u);
    
    char *h = "Hello!";
    printf("%s\n", h);
    printf("%c\n", h[0]);
    printf("%c\n", h[1]);
    printf("%c\n", h[2]);
    printf("%c\n", h[3]);
    printf("%c\n", h[4]);
    printf("%c\n\n", h[5]);
    printf("%c\n\n", *(h + 6) );
    printf("%s\n\n", h+4);
}
