#include <stdlib.h>
#include <stdio.h>
void maxHeapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
	if (left < n && arr[left] > arr[largest])
        largest = left;
	if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; i--)
        maxHeapify(arr, n, i);
    for (int i = n-1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;	
        maxHeapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    printf("Max-Heap:\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", arr[i]);
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    // int arr[100];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
	buildMaxHeap(arr, n);
	printArray(arr, n); 
	return 0;
}
/*
Time Complexity analysis
    Reccurence Relation: 
        T(n)=log(n)+log(n-1)+log(n-2)+......+log(1)
	    =log(n!)
            =n*log(n)-n+O(log n)
    Best Case: O(n logn)
    Worst Case: O(n logn)
    Average Case: O(n logn)
*/

