#include<iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;
int minJumps(int arr[],int n)
{
    if(n==0||arr[0]==0)
        return -1;

    int step=arr[0];
    int mxreach=arr[0];
    int jumps=1;

    for(int i=1;i<n;i++)
    {
        if(i==n-1)
            return jumps;
        mxreach=max(mxreach,i+arr[i]);
        step--;
        if(step==0)
        {
            jumps++;
            if(i>=mxreach)
                return -1;
            step=mxreach-i;
        }
    }
    return -1;
}
int main()
{
  int arr[] =   {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Minimum number of jumps to reach end is %d ", minJumps(arr,n));
  return 0;
}
