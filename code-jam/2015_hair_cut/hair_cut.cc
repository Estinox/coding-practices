#define _DEBUG 0
#include <cstdio>
#include <algorithm>

long customers_served(const long &time, const long *M, const int &B)
{
  long customers = 0;
  for (int i = 0; i < B; ++i)
  {
    customers += time / M[i] + 1;
  }

  return customers;
}

int main()
{
  int T = 0;
  scanf("%d", &T);

  for (int i = 0; i < T; ++i)
  {
    int B = 0, N = 0;
    scanf("%d %d", &B, &N);
    long M[B];

    long max_m = 0;
    for (int j = 0; j < B; ++j)
    {
      scanf("%ld", &M[j]);
      max_m = std::max(max_m, M[j]);
    }

    long lower_time = -1, upper_time = max_m * N;
    while (lower_time + 1 < upper_time)
    {
      long mid = (lower_time + upper_time) / 2;
      long mid_n = customers_served(mid, M, B);
      if (mid_n < N)
        lower_time = mid;
      else
        upper_time = mid;

#if _DEBUG
      printf("lower_time %ld, upper_time %ld, cs(lower) %ld, cs(upper) %ld\n"
             , lower_time
             , upper_time
             , customers_served(lower_time, M, B)
             , customers_served(upper_time, M, B));
#endif
    }

    int before_me = N - customers_served(upper_time - 1, M, B);

    for (int j = 0; j < B; ++j)
    {
#if _DEBUG
      printf("before me: %d, upper_time %ld, barber[%d] %ld\n", before_me, upper_time, j, M[j]);
#endif
      if (upper_time % M[j] == 0)
        before_me--;

      if (before_me == 0)
      {
        printf("Case #%d: %d\n", i + 1, j + 1);
        break;
      }
    }
  }

  return 0;
}
