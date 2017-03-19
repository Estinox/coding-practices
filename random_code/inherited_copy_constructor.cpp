#include <iostream>
#include <stdio.h>
#include <iostream>

class A {
public:
//  A(const A &rhs);
//  A();
//  A &operator=(A rhs);
  virtual void echo() { std::cout << "A " << val << std::endl; }

  int val;
};

class B : public A {
public:
  int b_val;

  void echo() override { std::cout << "B " << b_val << std::endl; }
};

//A::A(const A &rhs) : val(rhs.val) {
//  printf("Class A Copy construtor called on %d\n", rhs.val);
//}
//
//A::A() : val(0) { printf("Class A Constructor called\n"); }
//
//A &A::operator=(A rhs) {
//  printf("Class A Assignment operator called by %d with %d\n", val, rhs.val);
//  std::swap(rhs, *this);
//  return *this;
//}

int main() {
  A a;
  a.val = 1;
  a.echo();

  B b;
  b.b_val = 2;
  b.echo();

  A& a2 = b;
  a2.echo();

//  A a;
//  A a2(a);
//
//  printf("BBBBBBBBBB\n");
//
//  B b;
//  B b2;
//  b = b2;
}
