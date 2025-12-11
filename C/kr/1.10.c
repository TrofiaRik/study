#include <stdio.h>

int main(void) {
    int g;
    printf("Write input: \n");
    while ((g = getchar()) != 'k') {
        if (g == '\n') {
            putchar('\\');
            putchar('n');
        } else if (g == '\b') {
            putchar('\\');
            putchar('b');
        } else if (g == '\\') {
            putchar('\\');
        } else {
            putchar(g);
        }
    }
    return 0;
}
    