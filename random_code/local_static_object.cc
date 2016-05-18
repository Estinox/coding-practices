#include <stdio.h>

void helper()
{
  static int a = 0;

  printf("a = %d\n", a);
}

int main()
{
  helper();

//  printf("main::a = %d\n", a);
}
