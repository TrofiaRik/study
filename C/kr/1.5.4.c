#include <stdio.h>

// Simple wc (words count)

#define IN  1
#define OUT 0

int main(void)
{
    int c, nl, nw, nc, status;
    
    status = OUT;
    
    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n')
            ++nl;
                             
        if (c == ' ' || c == '\n' || c == '\t')
            status = OUT;
        
        else if (status == OUT) {
            status = IN;
            ++nw;
        } 
    }
    
    printf("Nr. of lines = %d\n", nl);
    printf("Nr. of chars = %d\n", nc);
    printf("Nr. WORDS = %d\n", nw);
    
    return 0;
}
