#include <iostream>

void print_it() {}

template <typename T> void print_it(T single) { std::cout << single << " "; }

template <typename... Tail, typename T>
void print_it(T head, Tail... tail) {
  std::cout << head << " ";
  print_it(tail...);
}

int main() { print_it(1, 2, "la", "ba", 2.3, true, false); }
