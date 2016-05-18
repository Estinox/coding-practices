#include <iostream>
#include <stdio.h>
#include <memory>

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

void factory(unique_ptr<Base> (*a)[])
{
  unique_ptr<Base> b1[2];
  for (int i = 0; i < 2; ++i)
    b1[i] = unique_ptr<Base>(new Base(i));

  a = &b1;
}

int main ()
{
  unique_ptr<Base> b1[2];
  for (int i = 0; i < 2; ++i)
    b1[i] = unique_ptr<Base>(new Base(i));

  return 0;
}

