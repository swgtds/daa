#include <stdio.h>
int a[7][3];
void sort(int a[][3], int n){
	int temp,i,j;
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++){
			if(a[i][2]< a[j][2]){
				temp=a[i][0];
				a[i][0]= a[j][0];
				a[j][0]= temp;
				
				temp=a[i][1];
				a[i][1]= a[j][1];
				a[j][1]= temp;
				
				temp=a[i][2];
				a[i][2]= a[j][2];
				a[j][2]= temp;
			}
		}
	}
}
void jobsequencing(int a[][3])
{
	int td[6], profit=0,i,j,t;
	for(i=0;i<6;i++)
	{
		td[i]=0;
	}
	for(i=0; i<7; i++)
	{
		t=a[i][1];
		if(td[t]==0)
		{
			profit=profit+a[i][2];
			td[t]=1;
			printf("\n%d", t);
			
		}
		else
		{
			for(j=t-1;j>0;j--)
			{
				if(td[j]==0)
				{
					profit=profit+a[i][2];
					td[j]=1;
					printf("\n%d", t);
					break;
				}
			}
		}
	}
	printf("Profit= %d", profit);
}
int main()
{
	int i,j;
	printf("enter the elements in array");
	for(i=0;i<7;i++)
	{
		for(j=0;j<3;j++)
		scanf("%d", &a[i][j]);
	}
	sort(a,7);
	for(i=0;i<7;i++)
	{
		for(j=0;j<3;j++)
		printf("%d\t", a[i][j]);
		printf("\n");
	}
	jobsequencing(a);
	return 0;        
}
/*
Time Complexity analysis
	Worst Case: O(n^2), when we will look for all the slots in the Gnatt Chart
        Average Case: O(n), as extra space is used in the above implementation
	Best Case: O(n^2), as n jobs search for m/2 slots
*/

