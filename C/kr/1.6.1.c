#include <stdio.h>

int main(void)
{
    /* copy input to output - 1st version 
    int c = getchar();
    
    while ( c != EOF )
    {
        putchar(c);
        c = getchar();
    }
    */
    
    /* copy input to outpur - 2nd version  
    int c;
    while ( (c = getchar()) != EOF )
    {
        putchar(c); 
    }
    */

    /* 1.6 - VERIFY THAT THE EXPRESSION getchar() != EOF is 0 or 1 */ 

    int c;
    while ( (c = getchar()) != EOF )
    {
        if (c != '\n') {
          printf( "getchar() != EOF -> %d\n", c != EOF );
        }
        //putchar(c);
    }      
    printf("After loop, getchar() is now == EOF? -> %d, (c = %d)\n", c != EOF, c);
    

}
