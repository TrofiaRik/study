#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *myfile = fopen("phonebook.csv", "a");
    if (myfile == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: ");
    char *number = get_string("Number: ");

    fprintf(myfile, "%s, %s\n",name, number);

    fclose(myfile);

}
