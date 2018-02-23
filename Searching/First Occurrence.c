/*
Two Questions:
1) Given a sorted array A (which has integers possibly with repetitions) and an integer q, return the index of  the 
first occurrence of q in A if q is present in A and -1 otherwise.
2) Given a sorted array A  and an integer q, return the index of  the 
first occurrence of  a number greater than q in A if such a number exists. Else it returns -1.

*/
#include <stdio.h>
int main()
{
	int a[14]={1,2,2,3,3,3,4,5,6,7,7,7,7,8};
	int k;
	scanf("%d",&k);
	int low=0,high=13;int mid;int c,c1;int flag=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(k==a[mid])
		{
			if(a[mid-1]==k)
				{high=mid-1;flag++;}
			else
				break;
		}
		else if(k>a[mid])
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	c=mid;
	low=0;high=13;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(k==a[mid])
		{
			if(a[mid+1]==k)
				{low=mid+1;flag++;}
			else
			{
				c1=mid;break;
			}
		}
		else if(k>=a[mid])
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	printf("First occurence of %d is at %d\n",k,c);
	printf("The next element after the multiple occurence of %d is %d",k,a[c1+1]);
	if(flag==0)
		printf("not found");
	return 0;
}
