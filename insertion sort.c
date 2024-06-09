//C Program to sort an array using Insertion Sort
 
#include <stdio.h>
int main(void)
{
    int n, i, j, temp;
    int arr[100];
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i < n; i++) 
    {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) 
        {
            temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
    printf("Sorted elements are:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
/*
Time Complexity analysis
    Best Case: When the array is sorted 
               T(n) = C*n
               thus O(n)
    Worst Case: O(n^2), where the array is in descending order
                T(n)=C*(n^2)\
    Average Case: O(n^2), when the array is randomly ordered
*/
