#include <iostream>

using namespace std;

class Base 
{
  public:
  int v;
  Base(int val=0);
  Base(const Base &obj);
};

Base::Base(int val)
  : v(val)
{
  cout << "Constructor\n";
}

Base::Base(const Base &obj)
  : v(obj.v)
{
  cout << "Copy Constructor\n";
}

Base IncrementBaseValue(Base& b)
{
  b.v++;
  return b;
}

int main ()
{
  Base b(1);

  Base e = IncrementBaseValue(b);
  b.v = 3;

  cout << b.v << endl;
  cout << e.v << endl;

  return 0;
}


