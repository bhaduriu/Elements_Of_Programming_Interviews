/*
Search a sorted array for an entry equal to its index, A[i] = i, where A[i]s are sorted
*/

#include <stdio.h>
int main()
{
	//int a[8]={-5,-2,-1,2,4,98,100,200};
	//int a[8]={-5,-2,-1,3,4,98,100,200};
	//int a[8]={-5,1,45,55,65,98,100,200};
	int a[8]={-5,-6,-7,-8,1,2,3,7};
	//int a[8]={0,1,2,3,4,5,6,7};
	int i,q;
	int low=0,high=7,mid,mid1;int loc=-1;int c=0;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==mid)
		{
			printf("Found at %d",mid);loc=mid;c++;
			break;
		}
		else if(a[mid]>mid)
			{high=mid-1;c++;}
		else
			{low=mid+1;c++;}
	}
	if(loc==-1)
		printf("NOT FOUND");
	printf("\n%d",c);
	return 0;
}
