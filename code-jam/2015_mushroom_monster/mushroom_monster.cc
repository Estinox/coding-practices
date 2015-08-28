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
    scanf("%d", &N);
    for (int j = 0; j < N; j+=2)
    {
      scanf("%d %d", &l[j], &l[j+1]);
      one += l[j] - l[j+1];
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
