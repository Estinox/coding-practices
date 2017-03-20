// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
  std::sort(A.begin(), A.end());

  std::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';

  int first = 0;
  if (A[0] != A[1])
    ++first;
  std::cout << "first=" << first << '\n';

  std::adjacent_difference(A.begin(), A.end(), A.begin(),
                           [](int x, int y) { return x != y ? 1 : 0; });

  std::copy(A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << '\n';

  return std::accumulate(A.cbegin() + 1, A.cend(), first) + 1;
}
