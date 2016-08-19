#include <iostream>

template <class... T_values> class Base {
public
  virtual void something(T_values... values) = 0;
};

class Derived1 : public Base<int, short, double> {
public:
  void something(int a, short b, double c) override;
};

class Derived2 : public Base<std::string, char> {
public:
  void something(std::string a, char b) override;
};

int main() {}
