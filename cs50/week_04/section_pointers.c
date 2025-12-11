/* 
* Data Types Table
* ------------------------
* data type ---- bytes --- 
* --------- ---- ---- ----
* int        --   4   ----
* char       --   1   ----    
* float      --   4   ----
* double     --   8   ----
* long long  --   8   ----
* string     --   -   ----
* ------------------------
* */

#include <stdio.h>
#include <stdint.h>
//#include <stdlib.h>
#include <string.h>

void draw_box(const int val);
void draw_hex(const int *ptr);

int main(void)
{
    int k;
    k = 5;
    
    int* pk;
    // draw_box(*pk);
    
    pk = &k;
    
    draw_box(k);
    draw_box(*pk);
    printf("Address inside pointer = %p\n", pk);
    
    draw_hex(pk);
}

void draw_box(const int val)
{
    int n = val;
    int count = 0;
    if (n == 0) count = 1; // handling special case of val as 0
    if (n < 0) n = -n; // handling val as negative
    while (n > 0) {
        n /= 10; // val = val/10 - fdrop the last digit by means of truncation
        count++;
    }    

    // Top border
    printf("+");
    for (int i = 0; i < count + 2; i++) printf("-");
    printf("+\n");

    // Text line
    printf("| %d |\n", val);

    // Bottom border
    printf("+");
    for (int i = 0; i < count + 2; i++) printf("-");
    printf("+\n");
}


void draw_hex(const int *ptr)
{
    int val = *ptr;
    int n = val;
    int count = 0;

    // Count digits (same as your version)
    if (n == 0)
        count = 1;
    if (n < 0)
        n = -n;
    while (n > 0) {
        n /= 10;
        count++;
    }

    // Prepare address string
    char addr_str[32];
    sprintf(addr_str, "%p", (void *)ptr); // will look like 0x7ffd6c4ea2ac

    // Calculate width — longest between value and address line
    int len_val = count + 2; // " %d "
    int len_addr = (int)strlen(addr_str) + 11; // " Address: " + addr
    int box_width = len_val > len_addr ? len_val : len_addr;

    // Top border
    printf("+");
    for (int i = 0; i < box_width; i++) printf("-");
    printf("+\n");

    // Value line
    printf("| %d", val);
    for (int i = 0; i < box_width - count - 2; i++) printf(" ");
    printf(" |\n");

    // Address line
    printf("| Address: %s", addr_str);
    int addr_line_len = 11 + (int)strlen(addr_str); // " Address: " + addr
    for (int i = 0; i < box_width - addr_line_len; i++) printf(" ");
    printf(" |\n");

    // Bottom border
    printf("+");
    for (int i = 0; i < box_width; i++) printf("-");
    printf("+\n");
}
