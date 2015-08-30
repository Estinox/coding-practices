#include <cstdio>
#include <algorithm>

int solve(const int &B, long const *M, const int &N)
{
  int served = 0;
  for (long time = 0;;++time)
  {
    for (int i = 0; i < B; ++i)
    {
      if (time % M[i] == 0)
        served++;

      if (served == N)
        return i+1;
    }
  }
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

    for (int j = 0; j < B; ++j)
    {
      scanf("%ld", &M[j]);
    }

    printf("Case #%d: %d\n", i+1, solve(B, M, N));
  }
}
