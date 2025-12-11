#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    
    // Open the memory card
      // FILE *f = fopen(filename, "r");
        
    // While there's still data left to read from the memory card
        
        // fread(data, size(512), number(1), inptr(FILE * to read))
            // check each 512b block for jpeg signature:
            // data[0] == ff -> data[1] == d8 -> data[2] == ff -> (data[3] & 0xf0) == 0xe0;

            // Open (create a new jpeg)
            // start and keep writing chunks of 512B UNTIL a new jpeg signature is found
            // close the file
        

}
