#define _DEBUG 0

#include <cstdio>
#include <algorithm>
#include <cassert>

int main()
{
#if _DEBUG
  FILE *files[] = {fopen("test.txt", "r")};
#else
  FILE *files[] = {fopen("A-small-practice.in", "r"), fopen("A-large-practice.in", "r")};
  FILE *outputs[] = {fopen("small.out", "w"), fopen("large.out", "w")};
#endif

#if _DEBUG
  for (int i = 0; i < 1; ++i)
#else
  for (int i = 0; i < 2; ++i)
#endif
  {
    long T = 0;
    fscanf(files[i], "%ld", &T);

    for (int t = 0; t < T; ++t)
    {
      long S = 0;
      fscanf(files[i], "%ld", &S);

      char a[S+2];
      fscanf(files[i], "%s", a);

      int level = 0;
      long ppl_needed = 0;
      for (long s = 0; s < S+1; ++s)
      {
        if (level < s)
        {
          ppl_needed += (s - level);
          level++;
        }
        level += (long) (a[s] - '0');

#if _DEBUG
        printf("%ld: ppl_needed %ld, level %d, %s\n", s, ppl_needed, level, a);
#endif
      }

      printf("Case #%d: %ld\n", t+1, ppl_needed);
#if !_DEBUG
      fprintf(outputs[i], "Case #%d: %ld\n", t+1, ppl_needed);
#endif
    }

#if !_DEBUG
    fclose(outputs[i]);
#endif
    fclose(files[i]);
  }
}

