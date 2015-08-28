#include <iostream>

using namespace std;

void printarray (int arg[][3], int length)
{
  for (int m = 0; m < length; ++m)
  {
    for (int n = 0; n < 3; ++n)
      cout << arg[m][n] << ' ';
  }
  cout << '\n';
}

int main ()
{
  int firstarray[] = {5, 10, 15};
  int secondarray[] = {2, 4, 6, 8, 10};

  int thirdArray[][3] = {
    {1,2,3}
    ,{2,3,4}
  };

  //printarray (firstarray, 3);
  //printarray (secondarray, 5);
  //
  printarray(thirdArray, 6);
}

