#include <iostream>

using namespace std;

class Base 
{
  public:
  int v;
  Base(int val=0);
  Base(const Base &obj);
  Base operator=(const Base that);
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

Base Base::operator=(Base that)
{
  cout << "Assignment\n";

  return that;
}

Base IncrementBaseValue(Base& b)
{
  b.v++;
  return b;
}

int main ()
{
  Base b;
  Base c;
  c = b;

  return 0;
}

