// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Custom add
    int le = strlen(argv[3]);

    // Check command-line arguments + custom validation (number of chars in argv[3]) + custom instructions
    if (argc != 4 || le > 4)
    {
        printf("+-----------------------------------------------------------+\n");
        printf("| Usage Instructions:                                       |\n");
        printf("+-----------------------------------------------------------+\n");
        printf("| 1. Arguments needed: ./volume input.wav output.wav factor |\n");
        printf("| 2. Factor format: only numeric values >= 0.0 and <= 99.9  |\n");
        printf("+-----------------------------------------------------------+\n");
        return 1;
    }
    
    // custom validations added:
    // check factor to contain only integers and decimal point
    // accept only one decimal point
    char alw_chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    int point = 0;
    int lim = sizeof(alw_chars) / sizeof(alw_chars[0]);
    for(int i = 0; i < strlen(argv[3]); i++) 
    {
        for(int m = 0; m < lim; m++) 
        {
            if (argv[3][i] == alw_chars[m]) 
            {
                if (argv[3][i] == alw_chars[10]) 
                {
                    ++point;
                    printf("decimal point detected -> valid char\n");

                    if (point > 1) 
                    {
                        printf("You cannot insert more tha one decimal point!\n");
                        return 1;
                    }
                    break;
                }
                else
                {
                    printf("char [%d] is ok\n", i);
                    break;
                }
            }
            else if (m == lim-1) 
            {
                printf("Please insert valid characters [0-9 | \".\"]\n");
                return 1;
            }
        }
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // FILE *append = fopen(argv[2], "a");
    // if (output == NULL)
    // {
    //     printf("Could not open file.\n");
    //     return 1;
    // }

    float factor = atof(argv[3]);

    // TEMP Custom: use fseek and ftell to check files sizes /////////////////////////////////////
    fseek(input, 0, SEEK_END); //--> move cursor to the end of file
    long si = ftell(input); //--> read cursor position in bytes, giving the actual size of the file
    fseek(input, 0, SEEK_SET); //--> return to the start

    fseek(output, 0, SEEK_END);
    long so = ftell(output);
    fseek(output, 0, SEEK_SET);
    
    printf("Input File Size = %ld\n", si);
    printf("Output File Size = %ld\n", so);
    ///////////////////////////////////////////////////////////////////////////////////////////////
    
    // TODO: Copy header from input file to output file - fread / fwrite of the first 44 byte
    uint8_t rbuffer[HEADER_SIZE]; //--> allocating buffer
    fread(rbuffer, HEADER_SIZE, 1, input); //--> read first 44 bytes (1pc./44byt) from input and put in rbuffer
    fwrite(rbuffer, HEADER_SIZE, 1, output); //--> write rbuffer to output, agaim 1pc of 44bytes

    // TEMP Custom: use fseek and ftell to check files sizes /////////////////////////////////////
    fseek(input, 0, SEEK_END); //--> move cursor to the end of file
    si = ftell(input); //--> read cursor position in bytes, giving the actual size of the file
    fseek(input, 0, SEEK_SET); //--> return to the start

    fseek(output, 0, SEEK_END);
    so = ftell(output);
    fseek(output, 0, SEEK_SET);
    
    printf("Input File Size = %ld\n", si);
    printf("Output File Size = %ld\n", so);
    ///////////////////////////////////////////////////////////////////////////////////////////////
  
    // TODO: Read samples from input file and write updated data to output file - samples are sequences of 2 bytes
    int16_t sample_buffer;
    const int SAMPLE_SIZE = 2;
    fseek(input, 44, SEEK_SET);
    fseek(output, 44, SEEK_SET);
    while (ftell(input) < si)
    {
        fread(&sample_buffer, SAMPLE_SIZE, 1, input); //--> read sample 
        sample_buffer *= factor; //--> edit sample
        fwrite(&sample_buffer, SAMPLE_SIZE, 1, output); //--> write to output
    }
    
    // TEMP Custom: use fseek and ftell to check files sizes /////////////////////////////////////
    //fseek(input, 0, SEEK_END); //--> move cursor to the end of file
    si = ftell(input); //--> read cursor position in bytes, giving the actual size of the file
    fseek(input, 0, SEEK_SET); //--> return to the start

    //fseek(output, 0, SEEK_END);
    so = ftell(output);
    fseek(output, 0, SEEK_SET);
    
    printf("Input File Size = %ld\n", si);
    printf("Output File Size = %ld\n", so);
    ///////////////////////////////////////////////////////////////////////////////////////////////

    // Close files
    fclose(input);
    fclose(output);
}
