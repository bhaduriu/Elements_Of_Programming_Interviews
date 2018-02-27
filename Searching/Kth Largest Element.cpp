/*
Expected O(n) complexity using Randomized Partitioning of pivot in Quick Select 
total elements = n
kth smallest = k
kth largest = (n-k)+1
*/

#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int randomPartition(int a[], int low, int high)
{
    int p,pivot,i,j;
    p=low+rand()%((high-low)+1);
    pivot=a[p];
    swap(&a[p],&a[high]);
    i=low-1;
    for(j=low;j<high;++j)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}
int kthSmallest(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int pos = randomPartition(arr, l, r);
        int p = pos - l + 1;
        if (p == k)
            return arr[pos];
        if (p > k)
            return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-p);
    }
    return -999;
}
int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = 7, k = 3;
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, n-k+1);
    return 0;
}
