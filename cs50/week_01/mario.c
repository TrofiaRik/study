#include <stdio.h>

//Prototypes
void print_col(int nc);

//Impl. Main (rows) func
int main(void)
{         
  const int n = 5;
  for (int row=0; row < n; row++)
  {
    print_col(n);
  }
}

//Impl. cols per row funct.
void print_col(int nc)
{
  for (int col = 0; col < nc; col++)
    {
      printf("# ");
    }
  printf("\n");
}
