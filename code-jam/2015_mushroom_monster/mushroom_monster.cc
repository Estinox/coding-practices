#include <algorithm>
#include <cstdio>
#include <cassert>

int main()
{
  int T = 0;
  scanf("%d", &T);
  assert (T >= 0);

  for (int i = 0; i < T; ++i)
  {
    assert (i >= 0);

    int N = 0, one = 0, two = 0;
    int l[N];
    scanf("%d %d", &N, &l[0]);

    printf("first: %d", l[0]);
    for (int j = 1; j < N; ++j)
    {
      scanf("%d", &l[j]);
      one += l[j-1] - l[j];
    }

    // Solve for two
    int max_rate = l[N-2] - l[N-1];
    for (int n = 0; n < N-1; ++n)
    {
      two += std::min(max_rate, l[n]);
    }

    printf("\n");

    printf("Case #%d: %d %d", i+1, one, two);
  }

  return 0;
}
