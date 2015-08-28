#include <iostream>


using namespace std;

class Test
{
public:
  Test();
  int a;
  unsigned int b;
};

Test::Test()
  :a(2*16-1)
   , b(2*16-1)
{
  cout << "Constructed Test\n";
}

int main ()
{
  Test t[3];

  unsigned long lu = 123123123lu;

  cout << "Test.a: " << t[0].a << " " << t[0].b << endl;

  cout << lu << endl;
}

