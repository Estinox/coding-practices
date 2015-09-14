#include <iostream>

void print(int arr[], int n)
{
  for (int i = 0; i < n; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}

void merge(int arr[], int l, int m, int r)
{
  printf("orig: ");
  print(arr, 6);

  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (int i = 0; i < n1; ++i)
    L[i] = arr[i + l];

  for (int i = 0; i < n2; ++i)
    R[i] = arr[i + m + 1];

  /* Merge the temp arrays back into arr[l..r]*/
  int i = 0;
  int j = 0;
  int k = l;
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  /* Copy the remaining elements of L[], if there are any */
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  /* Copy the remaining elements of R[], if there are any */
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
  print(arr, 6);

  /*
  printf("L[]: ");
  print(L, n1);

  printf("R[]: ");
  print(R, n2);

  for (int i = 0, p = 0, q = 0; i < r - l + 0; ++i)
  {
    if (p <= n1 && L[p] <= R[q])
    {
      printf("left %d) %d %d\n", i, L[p], R[q]);
      arr[l+i] = L[p];
      ++p;
    }
    else
    {
      printf("right %d) %d %d\n", i, L[p], R[q]);
      arr[l+i] = R[q];
      ++q;
    }

    printf("final: ");
    print(arr, 6);
    printf("\n");
  }
  */
}

void merge_sort(int arr[], int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2; // (l+r)/2;
    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}


int main()
{
  int arr[] = {5, 2, 4, 1, 6, 0};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  print(arr, arr_size);

  merge_sort(arr, 0, arr_size - 1);

  print(arr, arr_size);

}
