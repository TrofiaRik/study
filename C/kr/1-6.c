#include <stdio.h>

/* Copy std input to std output */ 
int main(void)
{
    int c;
    
    while ((c = getchar()) != EOF) {
        putchar(c);
        printf("\nChar is: %i\nEOF is: %i\n", c, getchar() != EOF);
       // printf("\nget char is: %i\n", getchar() != EOF);
    }

    printf("\nget char of EOF is: %i\n", c != EOF);
    printf("my c: %i\n", c);
    int e = EOF;
    printf("my eof is: %i\n", e);
}

