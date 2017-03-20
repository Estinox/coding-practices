#include <algorithm>
#include <iostream>
#include <iterator>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
  vector<int> v(N, 0);
  // std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, "
  // "));

  for (auto val : A) {
    if (val > N) {
      int max_count = *std::max_element(v.begin(), v.end());
      std::transform(v.begin(), v.end(), v.begin(),
                     [&](int n) { return max_count; });
    } else {
      v[val - 1]++;
    }
    // std::copy(v.cbegin(), v.cend(), std::ostream_iterator<int>(std::cout, "
    // ")); std::cout << '\n';
  }

  return v;
}
