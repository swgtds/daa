// Merge sort
#include <stdio.h>
void merge_sort(int[], int, int, int[]);
void merge(int[], int, int, int, int[]);
void copy(int[], int, int, int[]);
void merge_sort(int a[], int low, int up, int b[]) {
  int mid;
  if (low == up)
    return;
  mid = (low + up) / 2;
  merge_sort(a, low, mid, b);
  merge_sort(a, mid + 1, up, b);
  merge(a, low, mid, up, b);
  copy(a, low, up, b);
}
void merge(int a[], int low, int mid, int up, int b[]) {
  int k, l, m, f, s, i, j;
  k = l = low;
  m = mid + 1;
  f = mid;
  s = up;
  if (a[up] < a[mid]) {
    l = mid + 1;
    m = low;
    f = up;
    s = mid;
  }
  for (i = l, j = m; i <= f;)
    b[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
  while (j <= s)
    b[k++] = a[j++];
}

void copy(int a[], int low, int up, int b[]) {
  int i;
  for (i = low; i <= up; i++)
    a[i] = b[i];
}

int main() {
  int a[100], b[100], n, i;
  printf("Enter number of elements:");
  scanf("%d", &n);
  printf("Enter the values in array:");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("Before sorting:\n");
  for (i = 0; i < n; i++)
    printf("%d\n", a[i]);
  merge_sort(a, 0, n - 1, b);
  printf("\nAfter sorting:\n");
  for (i = 0; i < n; i++)
    printf("%d\n", a[i]);
  return 0;
}
