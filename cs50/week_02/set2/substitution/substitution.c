#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int validate(string key, int key_lenght);
string cipher(string k, string t);

// ** 1 ** GET key via argc and argv[] in the main function

int main(int argc, string argv[])
{
    // ** 2 ** Validate the number of arguments
    if (argc == 1 || argc > 2)
    {
        printf("%i arg/s, but only 1 arg is allowed (26 char. alphab.).\n", argc);
        return 1;
    }

    string key = argv[1];
    int key_length = strlen(argv[1]);
    // printf("LENGTH!!! %i\n", key_length);
    
    // Check & Validate key case
    for (int i = 0; i < key_length; i++)
    {
        // printf("MY PRE-KEY IS: %s\n", key);
        if (isupper(key[i]))
        {
            key[i] = tolower(key[i]);
        }
        // printf("MY CASE-VALIDATED KEY IS: %s\n", key);
    }

    // ** 2 ** VALIDATE key
    //  - Check length to be exactly 26 chars
    //  - Check for non-alphabetic characters - not accepted
    //  - Check for repeated characters - not accepted

    int ck = validate(key, key_length);
    if (ck == 1)
    {
        printf("Failed: error %i\n", ck);
        return 1;
    }

    // ** 3 ** GET plain_text
    string text = get_string("plaintext: ");
    // printf("plain = %s\n", text);

    // ** 4 ** CIPHER the plain_text via the key
    string ci = cipher(key, text);

    // ** 5 ** PRINT THE CIPHERTEXT & return 0;
    printf("ciphertext: %s\n", ci);
    return 0;
}

// Implementing the three VALIDATIONS in a 'cascade' function
int validate(string key, int key_length)
{
    if (key_length == 26)
    {
        for (int i = 0, n = key_length; i < n; i++)
        {
            if (isalpha(key[i]))
            {
                for (int ii = 0, nn = key_length; ii < nn; ii++)
                {
                    /*printf("iter %i - parent loop iter %i\n", ii, i);*/
                    if (ii == i)
                    {
                        /*printf("skipped %i\n", ii);*/
                        continue;
                    }
                    
                    /*printf("key parent: %c\n", key[i]);*/
                    /*printf("against: %c\n", key[ii]);*/
                    
                    if (key[i] == key[ii])
                    {
                        printf("No repetitions allowed (\'%c\')\n", (char) key[i]);
                        return 1;
                    }
                }
            // return 0;
            }
            else
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    return 0;
}

// Implement cipher function:
// * Create the mapping alphabet-to-cipherkey
// ** Preserve chars' cases
// *** No conversion of non-alphabetic chars

string cipher(string k, string t)
{
    const string a = "abcdefghijklmnopqrstuvwxyz";
    int length_a = strlen(a);

    string cipher = t;
    int mk = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        mk = 0;
        if (isupper(t[i]))
        {
            mk = 1;
            t[i] = tolower(t[i]);
            // printf("mk %i", mk);
            // printf("t[i] %c", t[i]);
        }
        for (int ii = 0; ii < length_a; ii++)
        {
            if (a[ii] == t[i])
            {
                if (mk == 1)
                {
                    cipher[i] = toupper(k[ii]);
                }
                else
                {
                    cipher[i] = k[ii];
                }
                /*printf("ciphertext: %s\n", cipher);*/
                break;
            }
        }
    }
    return cipher;
}
