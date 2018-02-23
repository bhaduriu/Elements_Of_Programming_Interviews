/*
Given a sorted array of n integers, find a pair of numbers (if any) that add upto k.
E.g. 4,6,17,23,30,50
For k = 29, solution is (6,23)
For k = 35, there is no solution

*/
#include <stdio.h>
int main()
{
	int a[6]={4,6,17,23,30,50};
	int k;
	scanf("%d",&k);
	int i=0,j=5;int flag=0;
	while(i<j)
	{
		if(a[i]+a[j]==k)
		{
			printf("Sum of: %d and %d.",a[i],a[j]);
			flag=1;
			return 0;
		}
		else if((a[i]+a[j])>k)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
	if(flag!=1)
		printf("Not Found.");
	return 0;
}
