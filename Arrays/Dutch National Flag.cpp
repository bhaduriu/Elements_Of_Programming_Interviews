#include <stdio.h>
int n=10;
int swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int pivot;int a[10]={30,13,27,90,3,30,44,50,19,30};
	scanf("%d",&pivot);
	int i=0,j=0;
	i=i-1;int temp,index;
	while(j<n)
	{
		if(a[j]<pivot)
		{
			i++;
			swap(&a[i],&a[j]);j++;
		}
		else if(a[j]==pivot)
		{
			j++;
		}
		else
		{
			swap(&a[j],&a[n-1]);n--;
		}
	}
	for(i=0;i<10;++i)
	{
			printf("%d ",a[i]);
	}
	return 0;
}
	
