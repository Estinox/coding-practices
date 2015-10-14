#include <stdio.h>

// Generates the Fibonacii sequence during compile time
// with the help of template metaprogramming
//
// To Compile: g++ -std=c++11 metaprogramming_fibonacci.cpp

// Specialized int template with recursive calls
template<int n>
struct Fibonacci
{
  static constexpr int value = Fibonacci<n-1>::value + Fibonacci<n-2>::value;
};

// Create base cases
template<>
struct Fibonacci<0>
{
  static constexpr int value = 0;
};

template<>
struct Fibonacci<1>
{
  static constexpr int value = 1;
};

int main()
{
  printf("%d", Fibonacci<20>::value);
  return 0;
}
