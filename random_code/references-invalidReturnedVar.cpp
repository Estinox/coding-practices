#include <iostream>
using namespace std;

int& func()
{
  int a = 0;
  return a;
}

int main()
{
  cout << func() << endl;
}
