#include <iostream>
#include <vector>

class MyClass {
public:
  void push(int i) { vec_.push_back(i); }
  void change(int &i) const { *ptr = i; }

  std::vector<int> vec_;
  int *ptr;
};

int main() {
  std::cout << "hi" << std::endl;
  MyClass c;
  c.push(2);

  for (auto const &v : c.vec_)
    std::cout << v << std::endl;

  int z = 3;
  c.change(z);
}
