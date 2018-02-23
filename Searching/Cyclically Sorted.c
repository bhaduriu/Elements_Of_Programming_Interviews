/*
Assume all elements are distinct e.g. 55,63,68,72,11,17,44,49

A[i] < A[i+1] < A[i+2] <…<A[n-1] < A[0] <…<A[i-1]
*/

#include <stdio.h>
int main()
{
	int a[8]={30,35,40,13,15,17,20,25},i,q;
	//for(i=0;i<8;++i)
		//scanf("%d",&a[i]);
	scanf("%d",&q);
	int low=0,high=7,mid,mid1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
			break;
		if(a[mid]<a[mid-1] && a[mid]<a[mid+1])
		{
			mid=mid-1;break;
		}
		else
		{
			if(a[mid]>a[0])
				low=mid+1;
			else
				high=mid+1;
		}
	}
	mid1=mid+1;
	//printf("%d %d",mid,mid1);
	low=0;high=mid;
	int loc=-1,loc1=-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==q)
		{
			printf("Found at %d",mid);loc=mid;
			return 0;
		}
		else if(q>a[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	low=mid1;high=7;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==q)
		{
			printf("Found at %d",mid);loc1=mid;
			return 0;
		}
		else if(q>a[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	if(loc==-1 && loc1==-1)
		printf("NOT FOUND");
	return 0;
}
