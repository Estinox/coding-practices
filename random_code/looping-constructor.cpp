#include <iostream>

using namespace std;

class Base 
{
  public:
  int v;
  Base(int val=0);
  Base(const Base &obj);
  Base operator=(const Base that);
  Base Increment();
  ~Base();
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

Base::~Base()
{
  cout << "Destroyed\n";
}


Base IncrementBaseValue(Base& b)
{
  b.v++;
  return b;
}

Base IncrementBaseValue(Base* b)
{
  b->v++;
  return *b;
}

Base Base::Increment()
{
  v++;
  return *this;
}

int main ()
{
  for (int i = 0; i < 2; ++i)
  {
    Base b;
  }


  return 0;
}

