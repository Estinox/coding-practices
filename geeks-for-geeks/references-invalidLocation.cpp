#include <iostream>
using namespace std;

int main ()
{
  int *ptr;
  int &ref = *ptr; // Reference to value at some random memory location

  cout << ref << endl;
}
