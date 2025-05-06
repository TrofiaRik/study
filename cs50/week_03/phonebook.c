#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}person;

int main(void)
{
    /*string names[] = {"David", "John", "Yuliia"};*/
    /*string numbers[] = {"+1-617-495-1000",  "+1-949-468-2750", "+1-617-495-1000",};*/
    /**/
    /*string name = get_string("Name: ");*/
    /*for (int i = 0; i < 3; i++)*/
    /*{*/
    /*    if (strcmp(names[i], name) == 0)*/
    /*    {*/
    /*        printf("\n\n\tName Found!\n\n");*/
    /*        printfprintf("Name: %s\n", names[i]);*/
    /*        printf("Phone: %s\n\n", numbers[i]);*/
    /**/
    /*        return 0;*/
    /*    }*/
    /*}*/
    /*printf("Not Found!");*/
    /*return 1;*/

    person people[3];
    
    people[0].name = "David";
    people[0].number = "+1-617-495-1000";

    people[1].name = "John";
    people[1].number = "+1-949-468-2750";

    people[2].name = "Yuliia";
    people[2].number = "+1-617-495-1000";

    string name = get_string("\nName: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(name, people[i].name) == 0)
        {
            printf("\nRecord Found!\n\n");
            printf("Name: %s\n", people[i].name);
            printf("Phone Number: %s\n\n", people[i].number);
            return 0;
        }
    }
    printf("Not Found!\n");
    return 1;
}
