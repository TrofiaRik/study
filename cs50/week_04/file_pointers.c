#include <stdio.h>

// In stdio we have: 
// fopen() - fclose()
// fgetc() - fputc()
// fread() - fwrite()
int main(void)
{
  FILE *ptw = fopen("phb.txt", "w+");
  FILE *ptr = fopen("phonebook.csv", "r");

  if (ptr == NULL || ptw == NULL) {
    printf("Invalid\n");
    return 1;
  }
  
  char chg;
  while ((chg = fgetc(ptr)) != EOF) {
      fputc(chg, ptw);      
      printf("%c", chg);
  }
  printf("\n");

  fseek(ptw, 0, SEEK_SET);

  char cha;
  while ((cha = fgetc(ptw)) != EOF) {
      printf("%c", cha);
  }
  printf("\n");

  fclose(ptr);
  fclose(ptw);
}
