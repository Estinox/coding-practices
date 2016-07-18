#include <iostream>
#include <stdio.h>

using namespace std;

class Base 
{
  public:
  int v;
  Base(int val=0);
  Base(const Base &obj);
  Base operator=(const Base& that);
  ~Base();
  Base Increment();
};

Base::Base(int val)
  : v(val)
{
  cout << "Constructor " << v << endl;
}

Base::Base(const Base &obj)
  : v(obj.v)
{
  printf("Copying %d to %d\n", v, obj.v);
}

Base Base::operator=(const Base& that)
{
  printf("Assigning %d to %d\n", that.v, v);

  return that;
}

Base::~Base()
{
  printf("Deleting %d\n", v);
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
  Base b;

//  Base b = Base(1);
//  Base* b_pointer = &b;
//
//  b = Base(2);
//
//  printf("%d %d\n", b_pointer->v, b.v);

  return 0;
}

