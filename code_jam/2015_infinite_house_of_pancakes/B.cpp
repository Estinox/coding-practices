#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
typedef long long LL;

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++)
  {
    cout << "Case #" << t << ": ";
    int n;
    cin >> n;
    int stuff[n];
    for (int i = 0; i < n; i++) cin >> stuff[i];
    int answer = 1000;
    for (int i = 1; i <= 8; i++)
    {
      int cur = i;
      for (int j = 0; j < n; j++)
      {
        cur += (stuff[j] - 1) / i;
        // cur += ceil(stuff[j]/i)-1;
        printf("%d: cur %d, stuff[%d] %d, val %d\n", i, cur, j, stuff[j], (stuff[j] - 1)/i);
      }
      answer = min(answer, cur);

      printf("%d: answer %d\n", i, answer);
    }
    cout << answer << endl;
  }
  exit(0);
}
