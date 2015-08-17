#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <istream>
#include <iterator>
using namespace std;

int main()
{
  istream_iterator<int> begin(cin), end;
  vector<int> v(begin, end);

  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    cout << *it << endl;

  return 0;
}
