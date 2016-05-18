
#include <stdio.h>

// Uses dynamic programming - tabulation to
// store the previosu 2 fibonacci numbers
//
// Run Time: O(N)
// Space: O(1)
int IterativeFibonacci(int n)
{
  if (n == 0)
    return 0;

  int n1 = 0, n2 = 1;

  for (int i = 2; i <= n; ++i)
  {
    int n3 = n1 + n2;
    n1 = n2;
    n2 = n3;
  }

  return n2;
}

int main()
{
  printf("%d", IterativeFibonacci(21));
  return 0;
}
