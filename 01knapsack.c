#include<stdio.h>
int max(int a,int b){
	if (a>b){
		return a;
	}else{
		return b;
	}
	
}
int knapsack(int W,int wt[],int val[],int n){
	int i,w,k;
	int knap[n+1][W+1];
	for(i=0;i<=n;i++){
		for(w=0;w<=W;w++){
			if(i==0|| w==0)
				knap[i][w]=0;
			else if (wt[i-1]<=w)
				knap[i][w]=max(val[i-1]+knap[i-1][w-wt[i-1]],knap[i-1][w]);
			else
				knap[i][w]=knap[i-1][w];
			}
		}
			printf("Items are:\n");
	i=n,k=W;
			while(k>0)
			{
				
				if(knap[i][k]!=knap[i-1][k]){
						printf("%d\n",i);
					i=i-1;
					k=k-wt[i];
				}
				else
				i=i-1;
			}
	return knap[n][W];
}
int main(){
	int val[5],wt[5],i,n=5;
	printf("Enter the weight:");
	for(i=0;i<n;i++)
	{
		scanf(" %d",&wt[i]);
	}
	printf("Enter the cost:");
	for(i=0;i<n;i++)
	{
		scanf(" %d",&val[i]);
	}
	int W=20;
	n=sizeof(val)/sizeof(val[0]);
	printf("The solution is:%d",knapsack(W,wt,val,n));
	return 0;
}
