#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>


struct MyStruct
{
  int a,b;
};

std::ostream& operator<<(std::ostream& out, MyStruct const& s)
{
  out << s.a << " " << s.b << std::endl;
  return out;
}

template <int N>
struct MyTemplate {
  using self_type_t = MyTemplate<N>;
  using int_array_t = std::array<MyStruct, N>;

  std::string name;
  int_array_t int_array;

  friend std::ostream& operator<<(std::ostream& out, int_array_t const& arr)
  {
    for (auto const& a : arr)
      out << a << std::endl;
    return out;
  }

  friend std::ostream& operator<<(std::ostream& out, self_type_t const& self)
  {
    out << self.name; // << " " << self.int_array;

    // This works:
    std::copy(self.int_array.cbegin(), self.int_array.cend(), std::ostream_iterator<MyStruct>(out, "\n"));
    return out;
  }
};

int main ()
{
  MyTemplate<3> t; // = {std::string("lala"), MyStruct{{1,2}, {3,4}, {5,6}}};
  t.name = "lala";
  t.int_array[0] = {1,2};
  t.int_array[1] = {3,4};
  t.int_array[2] = {5,6};

  std::cout << t;
}
