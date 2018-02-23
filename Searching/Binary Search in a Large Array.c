/*
The first n cells of an array A of size N contains  distinct integers sorted in increasing order. 
The remaining cells contain a very large integer MAXINT. 
The integers in the first n cells are all smaller than MAXINT. 
The array may be arbitrarily large and you don’t know n to start with. 
Given a query integer q, search for q in A.

*/
#include <stdio.h>
#define N 20
#define MAXINT 200000
int main()
{
	int a[N]={2,4,6,9,13,17,20,23,30,32,40,45,50,53,MAXINT,MAXINT,MAXINT,MAXINT,MAXINT,MAXINT};
	int k;
	scanf("%d",&k);
	int i=1;int x;
	int flag=0;
	int low=0,high=N-1;i=1;int j=1;int mid;
	while(j<=i)
	{
		if(k==a[i-1])
		{
			printf("Found at %d.",i-1);
			flag=1;
			break;
		}
		if(k>a[i-1])
		{
			i*=2;
		}
		else
		{
			j=i/2;break;
		}
	}
	i=i-1;j=j-1;
	if(flag!=1)
	{
		while(j<=i)
		{
			mid=(j+i)/2;
			if(k==a[mid])
			{
				printf("Found at %d.",mid);
				flag=1;
				break;
			}
			else if(k>a[mid])
			{
				j=mid+1;
			}
			else
			{
				i=mid-1;
			}
		}
		if(flag!=1)
			printf("Not Found.");
	}
	i=1;
	while(a[i-1]<MAXINT)
	{
		i*=2;
	}	
	j=i/2;mid=0;
	while(j<=i)
	{
		mid=(j+i)/2;
		if(MAXINT==a[mid])
		{
			printf("Change over point at %d.",mid);
			break;
		}
		else
		{
			j=mid+1;
		}
	}
	return 0;
}
