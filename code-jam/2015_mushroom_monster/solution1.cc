#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;
typedef long long LL;

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    int n;
    string stuff;
    cin >> n >> stuff;
    int add = 0;
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
      int k = (stuff[i] - '0');
      if ((add + sum < i)  && k > 0)
      {
        add += (i - add - sum);
      }
      sum += k;
    }
    cout << "Case #" << t << ": ";
    cout << add << endl;
  }
  exit(0);
}
