#include <stdio.h>
#include <algorithm>

int main()
{
  int a[] = {1, -2, 3, 10, -4, 7, 2, -5};

  int sum_so_far = 0;
  int current_sum = 0;

  int n = sizeof(a)/sizeof(a[0]);

  for (int i = 0; i < n; ++i)
  {
    current_sum += a[i];
    sum_so_far = std::max(sum_so_far, current_sum);
    current_sum = std::max(0, current_sum);
  }

  printf("%d", sum_so_far);
}
