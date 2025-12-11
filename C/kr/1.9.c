#include <stdio.h>
/* count tabs, blanks, newlines, in input*/
int main(void) {
    int g;
    printf("Write input: \n");
    
    int i = 0;
    
    while ((g = getchar()) != 'k') {
       
        if (g == ' ') {
        
            if (i == 0) {
                i++;
                putchar(g);
            }
            
        }
        
        if (g != ' ') {
            if (i == 1) i = 0;
            putchar(g);
        }
        
    }=
}
    