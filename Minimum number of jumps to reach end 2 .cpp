#include<iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;
int minJumps(int arr[],int n)
{
    if(n==0||arr[0]==0)
        return -1;
    int jumps[n];
    jumps[n-1]=0;
    for(int k=n-2;k>=0;k--)
    {
        if(arr[k]==0)
            jumps[k]=-1;
        else if(arr[k]>=n-k-1)
            jumps[k]=1;
        else
        {
            int mx=INT_MAX;
            for(int j=k+1;j<n&&j<=k+arr[k];j++)
            {
                if(mx>jumps[j]&&jumps[j]!=-1)
                    mx=jumps[j];
            }
            if (mx!=INT_MAX)
                jumps[k] = mx + 1;
            else
                jumps[k] = -1;
        }
    }

    return jumps[0];
}
int main()
{
  int arr[] =   {1, 3, 6, 1, 0, 9};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Minimum number of jumps to reach end is %d ", minJumps(arr,n));
  return 0;
}
