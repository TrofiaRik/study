#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* TO DO:
*  1 open memory card
*  2 look for the begining of jpg file
*  3 open a new jpeg file where to store the found data
*  4 write blocks of 512 bytes, until a new jpeg is found
*/ 

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILENAME\n");
        return 1;
    }
    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    FILE *n_file;
    char filename[8];
    // The data buffer for the date being read must be created before calling fread
    uint8_t data_buffer[512];

    // create index for 

    // While there's still data left to read from the memory card
    int idx = 0;

    while (fread(data_buffer, 1, 512, card) == 512)
    {
        fread(data_buffer, 1, 512, card);
        if (data_buffer[0] == 0xff && data_buffer[1] == 0xd8 &&
            data_buffer[2] == 0xff && (data_buffer[3] & 0xf0) == 0xe0)
        {       
            if (idx == 0)
            {    
                sprintf(filename, "%03i.jpg", idx);
                FILE *n_file = fopen(filename, "w");
                if (n_file == NULL)
                    return 1;
                fwrite(data_buffer, 1, 512, n_file);
                idx++;
            }
            else 
            {
                fclose(n_file);
                sprintf(filename, "%03i.jpg", idx);
                FILE *n_file = fopen(filename, "w");
                if (n_file == NULL)
                    return 1;
                fwrite(data_buffer, 1, 512, n_file);
                idx++;
            }
        }
        else
        {
            if (idx != 0)
            {
                fwrite(data_buffer, 1, 512, n_file);
            }
        }    
    }
    // close the file
    fclose(n_file);    
}
