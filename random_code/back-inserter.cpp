#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main ()
{
  int n = 10; 
 
  vector<int> v;
  iota_n (v.begin(), 100, back_inserter(v));
 
  random_shuffle (v.begin(), v.end());                         // shuffle
  copy (v.begin(), v.end(), ostream_iterator<int> (cout, "\n")); // print
}
