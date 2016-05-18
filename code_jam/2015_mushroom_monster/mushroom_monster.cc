#define _DEBUG 0

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
    scanf("%d", &N);

    int l[N];
    scanf("%d", &l[0]);

    int max_rate = 0;

    for (int j = 1; j < N; ++j)
    {
      scanf("%d", &l[j]);
      one += std::max(0, l[j-1] - l[j]);
#if _DEBUG
      printf("%d ", l[j]);
#endif
      max_rate = std::max(l[j-1] - l[j], max_rate);
    }
#if _DEBUG
    printf("\n");
#endif

    // Solve for two
#if _DEBUG
    printf("max_rate: %d\n", max_rate);
#endif

    for (int n = 0; n < N-1; n++)
    {
#if _DEBUG
      printf("two: %d, l[%d] %d\n", two, n, l[n]);
#endif
      two += std::min(max_rate, l[n]);
    }

    printf("Case #%d: %d %d\n", i+1, one, two);
  }


  return 0;
}
