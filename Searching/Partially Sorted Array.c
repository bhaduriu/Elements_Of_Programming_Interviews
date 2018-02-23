/*
You are given a sequence of n distinct elements consisting of n/k subsequences of  k elements each. 
The elements in a subsequence are all smaller than the elements in the next subsequence. 
But each subsequence is unsorted. 
We want to search for an element q in the array and report it if found. 
If the element q is not found, we should report the largest element smaller than q and the smallest element greater than q in the array. 
Implement  an efficient algorithm for the problem.

*/
#include <stdio.h>
#define N 20
#define K 4
#define MAX_INT 2147483646
int main()
{
    int a[N]={1,3,7,5,13,15,10,9,25,29,20,19,35,30,33,42,55,45,60,67};
    int s;
    scanf("%d",&s);
    int low=0,high=N-K,mid;int c=0;
    while(low<high)
    {
        mid=((low+high)/2)-c;
        if(a[mid]==s)
            break;
        else if(s>a[mid] && s<a[mid+K])
        {
            low=mid;high=mid+4;break;
        }
        else if(s<a[mid] && s>a[mid-K])
        {
            high=mid;low=mid-K;break;
        }
        else if(s>a[mid])
            low=mid+K;
        else if(s<a[mid])
            high=mid-K;
        c+=K/2;
    }
    int i,flag=0;int max=0,min=MAX_INT;
    for(i=low;i<=high+K;++i)
    {
        if(s==a[i])
        {
            printf("%d found at index %d.",s,i);
            flag=1;
            break;
        }
        else if(a[i]<s)
        {
            if(a[i]>max)
                max=a[i];
        }
        else if(a[i]>s)
        {
            if(a[i]<min)
                min=a[i];
        }
    }
    if(flag==0)
    {
        printf("Largest element smaller than %d is %d.\n The smallest element greater than %d is %d",s,max,s,min);
    }
    return 0;
}
