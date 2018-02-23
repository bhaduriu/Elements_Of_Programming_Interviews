/*
UNIMODAL ARRAY
EXAMPLE I/O
E.g. 12, 14, 27, 33, 26, 17, 12,7
Assume all elements are distinct
A[i] < A[i+1], 1 ≤ i  < m
A[i] > A[i+1], m ≤ i < n
How to search for an element q given by the user? 
*/

#include <stdio.h>
int main()
{
	int a[8],i,q;
	for(i=0;i<8;++i)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	int low=0,high=7,mid,mid1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]>a[mid-1] && a[mid]>a[mid+1])
			break;
		else if(a[mid]>a[mid-1] && a[mid]<a[mid+1])
			low=mid+1;
		else
			high=mid-1;
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
		else if(q<a[mid])
			low=mid+1;
		else
			high=mid-1;
	}
	if(loc==-1 && loc1==-1)
		printf("NOT FOUND");
	return 0;
}
