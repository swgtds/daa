#include<stdio.h>
void sortRow(int arr[][4],int n,int m ){
	int t,i,j,k;
	for ( i=0;i<n-1;i++){
		for ( j=i+1;j<n;j++){
				if (arr[i][3]<arr[j][3]){
				t=arr[i][0];
				arr[i][0]=arr[j][0];
				arr[j][0]=t;
				
				t=arr[i][1];
				arr[i][1]=arr[j][1];
				arr[j][1]=t;
				
				t=arr[i][2];
				arr[i][2]=arr[j][2];
				arr[j][2]=t;
				
				t=arr[i][3];
				arr[i][3]=arr[j][3];
				arr[j][3]=t;
			}
		}
	}
	printf("Sorted Array\n");
	for (i=0;i<n;i++){
		for(j=0;j<m;j++)
			printf("%d\t",arr[i][j]);
		printf("\n");
	}
}
void knapsack(int arr[][4],int n,int WS)
{
	int i, profit=0;
	for(i=0;i<n;i++)
	{
		if(arr[i][2]<WS)
		{
			profit=profit+arr[i][1];
			WS=WS-arr[i][2];
		}
		else
		{
			profit=profit+WS*arr[i][3];
			WS=0;
			break;
		}
	}
	printf("\nprofit is %d", profit);
}
int main(){
	int n,m,i,j,WS=15;
	printf("Enter the no. of items:");
	scanf("%d",&n);
	m=4;
	int arr[n][m];
	printf("Enter the values of items:");
	for (i=0;i<n;++i){
		scanf("%d",&arr[i][0]);}
	printf("Enter the values of profit:");
	for (i=0;i<n;++i){
		scanf("%d",&arr[i][1]);}
	printf("Enter the values of weight:");
	for (i=0;i<n;++i){
		scanf("%d",&arr[i][2]);}
	printf("Enter the values of cost compute per unit:");{}
	for (i=0;i<n;++i){
		scanf("%d",&arr[i][3]);}
	printf("Input Array\n");
	for( i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	sortRow(arr,n,m);
	knapsack(arr,n,WS);
	return 0;
	
}
