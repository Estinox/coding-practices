#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <string>

int main() {
//  // construction uses aggregate initialization
//  std::array<int, 3> a1{
//    {1, 2, 3}}; // double-braces required in C++11 (not in C++14)
//  std::array<int, 3> a2 = {1, 2, 3}; // never required after =
//  std::array<std::string, 2> a3 = {std::string("a"), "b"};
//
//  // container operations are supported
//  std::sort(a1.begin(), a1.end());
//  std::reverse_copy(a2.begin(), a2.end(),
//      std::ostream_iterator<int>(std::cout, " "));
//
//  std::cout << '\n';
//
//  // ranged for loop is supported

  std::array<int, 3> m;
  for (int i = 0; i < 3; ++i)
  {
    int ii;
    std::cin >> ii;
    m[i] = ii;
  }


  for (auto const& s : m)
    std::cout << s << ' ';
}
