/*
Partition the array into min candidates and max candidates by comparing successive pairs,
this will give (n/2)-1 comparisons to find the min from the min candidates and (n/2)-1 
comparisons to find the max from the max candidates, yielding a total of (3n/2)-2 comparisons
Total cost: 3 comparisons per 2 elements = 3n/2
*/

#include <iostream>
#include <limits.h>
#define N 6
using namespace std;

int main()
{
    int a[N]={3,2,5,1,2,4};
    int max=INT_MIN,min=INT_MAX;
    for(int i=0;i<N;i+=2)
    {
        if(i+1==N)//checking for odd sized array
        {
            if(a[i]>max)
                max=a[i];
            else
                min=a[i];
        }
        else// for all other even sized array
        {
            if(a[i]>a[i+1])
            {
                if(a[i]>max)
                    max=a[i];
                if(a[i+1]<min)
                    min=a[i+1];
            }
            else
            {
                if(a[i+1]>max)
                    max=a[i+1];
                if(a[i]<min)
                    min=a[i];
            }
        }
    }
    cout<<"Max: "<<max<<" and Min: "<<min<<endl;
    return 0;
}
