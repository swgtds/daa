#include <stdio.h>
int bsearch(int a[], int l, int r, int x){
 while (l<=r)
 {
    int mid=l+(r-l)/2;
    if(a[mid]==x)
        return mid;
    else if(a[mid]>x)
        return bsearch(a,l,mid-1,x);
    else 
        return bsearch(a,mid+1,r,x);
 }
  return -1;
}
int main(){
    int x,i,n,a[100];
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter thje elements in the array");
    for ( i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the element to be searched:");
    scanf("%d", &x);
    int res=bsearch(a,0,n-1,x);
    if(res==-1)
        printf("Element is not present");
    else
        printf("Element is present at index %d", res);
    return 0;
}

/*
Time Complexity analysis
    Best Case: O(1) when the central index would match directly match the desired search value
    Worst Case: O(log n)
*/