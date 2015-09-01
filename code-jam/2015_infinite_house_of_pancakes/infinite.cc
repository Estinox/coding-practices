#define _DEBUG 1

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
  int T;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    int D;
    cin >> D;

    vector<int> P;
    long sum = 0;
    int largest_p = 0;
    for (int d = 0; d < D; ++d)
    {
      int v;
      cin >> v;
      sum = v;
      P.push_back(v);
      largest_p = max(largest_p, P[d]);
#if _DEBUG
      cout << v << " ";
#endif
    }

    long largest_split = 0;
    long shortest_minute = sum;
    for (int split = 2; split < largest_p; ++split)
    {
      long minutes = ceil(sum * 1.0 / split) - 1 + split;
      //printf("sum %ld, split %d, %f %f\n", sum, split, ceil((double) (sum/(double)split)), (double)(sum/(long)split));
      if (shortest_minute >= minutes)
      {
        shortest_minute = minutes;
        largest_split = split;
      }

#if _DEBUG
      //printf("split %d: shortest minute %ld, largest split %ld, largest p %d\n", split, shortest_minute, largest_split, largest_p);
#endif
    }

    int special = 0;
    for (int d = 0; (unsigned long)d < P.size(); ++d)
    {
      if (largest_split > 0 && P[d] > largest_split)
      {
        while (P[d] > largest_split)
        {
          P[d] = P[d] - largest_split;
          P.push_back(largest_split);
          special++;
        }
      }
    }

    int moves = *max_element(P.begin(), P.end());


#if _DEBUG
    printf("special %d, moves %d, shortest minute %ld, largest split %ld, largest p %d\n", special, moves,  shortest_minute, largest_split, largest_p);
#endif

    printf("Case #%d: %d\n", i+1, special + moves);
  }
}
