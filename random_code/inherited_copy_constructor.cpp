#include <iostream>
#include <stdio.h>

class A
{
public:
  A(const A& rhs);
  A();
  A& operator=(A rhs);

  int val;
};

class B : A
{
  public:
  int b_val;
};

A::A(const A& rhs)
  :val(rhs.val)
{
  printf("Class A Copy construtor called on %d\n", rhs.val);
}

A::A()
  :val(0)
{
  printf("Class A Constructor called\n");
}

A& A::operator=(A rhs)
{
  printf("Class A Assignment operator called by %d with %d\n", val, rhs.val);
  std::swap(rhs, *this);
  return *this;
}

int main()
{
  A a;
  A a2(a);

  printf("BBBBBBBBBB\n");

  B b;
  B b2;
  b = b2;
}
