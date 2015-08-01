#include <stdio.h>
#include <iostream>

using namespace std;
 
/* Function to swap values at two pointers */
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
  
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n, int c) 
{
   int j; 
   if (i == n)
       printf("%s\n", a);
   else
   {
       for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          cout << "1 (" << c << "): " << a << " (i,j, n) (" << i << ", " << j << " " << n << ")" << endl;
          permute(a, i+1, n, c+1);
          cout << "2 (" << c << "): " << a << " (i,j, n) (" << i << ", " << j << " " << n << ")" << endl;
          swap((a+i), (a+j)); //backtrack
          cout << "3 (" << c << "): " << a << " (i,j, n) (" << i << ", " << j << " " << n << ")" << endl;
       }
   }
} 

/* Driver program to test above functions */
int main()
{
   char a[] = "ABC";  
   permute(a, 0, 2, 0);
   getchar();
   return 0;
}
