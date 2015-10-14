
#include<stdio.h>


// Very slow, does not take advantage of overlapping subproblems
// of calculating the same Fibonacci number
// Can be improved with tabulation- dyanamic programming, q4
//
// Run Time Complexity: O(2^N)
// Space Complexity: O(N) with function stacks
int RecursiveFibonacci(int n)
{
  if (n <= 1)
    return n;

  return RecursiveFibonacci(n - 1) + RecursiveFibonacci(n - 2);
}

int main ()
{
  printf("%d", RecursiveFibonacci(20));
  return 0;
}

