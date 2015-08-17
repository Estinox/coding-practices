#include <istream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
  istream_iterator<int> is(cin), end;

  vector<int> v(is, end);

  for (vector<int>::iterator it = vector.begin(); it != end; ++it)
  {
    cout << *it << endl;
  }

}
