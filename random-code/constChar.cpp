#include <iostream>

using namespace std;

void print(char* c)
{
  cout << "Non const\n";
}

void print(const char* c)
{
  cout << "Const version\n";
}

int main()
{
  char me[] = "One Long String";
  const char* cme = &(me[0]);

  print(cme);

  return 0;
}
