#include <cs50.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    // check for usage, must be 2 CLA
    if (argc != 2)
    {
        printf("Please insert the file name (one only|!)\n");
        return 1;
    }

    // open FILE and verify its existance
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("The file %s was not found!\n", argv[1]);
        return 1;
    }

    // create buffer for FILE
    uint8_t buffer[4]; // unsigned integer of size 1 byte -

    // create an array of signature bytes - 0x25 0x50 0x44 0x46
    uint8_t signature[] = {0x25, 0x50, 0x44, 0x46};
  
    // read first 4 bytes from the FILE
    // fread(buffer, sizeof(uint8_t), 4, input);
    if (fread(buffer, sizeof(uint8_t), 4, input) != 4)
    {
        printf("File too small / read error.\n");
        fclose(input);
        return 1;
    }
    
    // Compare signatures
    // if (memcmp(buffer, signature, sizeof(signature)) != 0)
    // {
        // printf("Error - not a PDF!\n");
        // fclose(input);
        // return 1;
    // }

    // check the first 4 bytes aginst the signature bytes
    for (int i = 0; i < sizeof(signature); i++)
    {
        if (signature[i] != buffer[i])
        {
            printf("Error - not a pdf!\n");
            return 1;
        }
    }
    // print outcome
    printf("It's a match! Our file is a pdf!\n");
    // close the file
    fclose(input);
    return 0;
}
