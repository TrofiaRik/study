#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // ** 1 ** PROMPT USER AND GET THE CC NUMBER
    long cc_num = get_long("Number: ");
    /*}*/
    /*while (cc_num < 0);*/
    if (cc_num < 999999999999)
    {
        printf("INVALID\n");
    }
    else 
    {
        // ** 2 ** FOR LOOPS A AND B, CALCULATING THE CHECKSUM  
        int psum = 0;
        long limit = cc_num * 10;
        int a_digit; // LAST DIGIT OF LOOP A SEQUENCE - RETAINING THE LAST
        int b_digit; // DIGIT OF LOOP B SEQUENCE - RETAINING THE LAST
        int counter = 0;
        // -- FOR LOOP A
        for (long mod = 100; mod < limit; mod *= 100)
        {
            // Extracting the single alternate digits starting from second to last 
            long mod_b = mod / 10;
            a_digit = (cc_num % mod) / mod_b;
            
            // Double each selected Number
            int a_digit_d = a_digit * 2;
            
            if (a_digit_d < 10)
            {
                psum += a_digit_d;
            }
            else 
            {
                psum += (a_digit_d % 10) + (a_digit_d / 10);
            }
            counter += 1;      
        }
        // -- FOR LOOP B, alternate digits starting from the last
        for (long mod = 10; mod < limit; mod *= 100)
        {
            long mod_b = mod / 10;
            b_digit = (cc_num % mod) / mod_b;
            psum += b_digit;
        
        // Add variables for phase 2 checks
            counter += 1;
        }

        // ** 3 ** CHECK FOR CARD LENGHT AND STARTING DIGITS
        // --company--||--digits--||---start---||
        //    ANEX    ||    15    ||  34 or 37 ||
        // MASTERCARD ||    16    ||   51->55  ||
        //    VISA    || 13 or 16 ||     4     || 

        if (psum % 10 == 0)
        {
            if (counter == 15 && b_digit == 3 && (a_digit == 4 || a_digit == 7))
            {
                printf("AMEX\n");
            }
            else if (counter == 16 && a_digit == 5 && b_digit >= 1 && b_digit <= 5)
            {
                printf("MASTERCARD\n");
            }
            else if ((counter == 13 && b_digit == 4) || (counter == 16 && a_digit == 4))
            {
                printf("VISA\n");
            }
            else 
            {
                printf("INVALID\n");
            }
        }
        else 
        {
            printf("INVALID\n");
        }
  }  
}
