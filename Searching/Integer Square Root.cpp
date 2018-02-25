/*
WAP to accept a non negative integer and returns the largest integer whose square
is less than or equal to the given integer. 
I/O if k=16 then return 4; if k=300 then return 17
*/
#include <iostream>
using namespace std;

int main()
{
    int k;cin>>k;
    int low=0,high=k;int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(mid*mid<=k)
            low=mid+1;
        else
            high=mid-1;
    }
    cout<<low-1;
}
