#include<iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;
int minJumps(int arr[],int n)
{
    if(n==0||n==1)
        return n;
    if(arr[0]==0)
        return -1;
    int jumps[n];
    jumps[0]=0;
    for(int k=1;k<n;k++)
    {
        for(int j=0;j<k;j++)
        {
            if(k<=j+arr[j]&&jumps[j]!=-1)
            {
                jumps[k]=jumps[j]+1;
                break;
            }

        }
    }

    return jumps[n-1];
}
int main()
{
  int arr[] = {1, 3, 6, 3, 0,0,0,2, 3, 6, 8, 9, 5,24,30,0,0,0,0,54,65,7,68,79,89,9};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Minimum number of jumps to reach end is %d ", minJumps(arr,n));
  return 0;
}
