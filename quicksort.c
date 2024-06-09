#include <stdio.h>
void quick_sort(int[], int, int);
int partitioning(int[], int, int);
void swap(int[], int, int);
void quick_sort(int a[], int low, int up) {
  int k;
  if (up < low)
    return;
  k = partitioning(a, low, up);
  quick_sort(a, low, k - 1);
  quick_sort(a, k + 1, up);
}
int partitioning(int a[], int low, int up) {
  int pivot, i, j;
  pivot = up;
  i = low - 1;
  j = up;
  while (i < j) {
    while (a[++i] <= a[pivot] && i < j)
      ;
    while (a[--j] >= a[pivot] && j > i)
      ;
    if (i < j)
      swap(a, i, j);
  }
  if (i < pivot)
    swap(a, i, pivot);
  return i;
}
void swap(int a[], int i, int j) {
  int temp;
  temp = a[i];
  a[i] = a[j];
  a[j] = temp;
}
int main() {
  int a[100], n, i;
  printf("Enter the number of elements:");
  scanf("%d", &n);
  printf("Enter the values into the array:");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("Before sorting:\n");
  for (i = 0; i < n; i++)
    printf("%d\n", a[i]);
  quick_sort(a, 0, n - 1);
  printf("\nAfter sorting\n");
  for (i = 0; i < n; i++)
    printf("%d\n", a[i]);
  return 0;
}

/*
Time Complexity analysis
    Best Case: O(n*log n)
    Worst Case: O(n^2)
    Average Case: O(n*log n),
    where n is the no. of elements
    */
