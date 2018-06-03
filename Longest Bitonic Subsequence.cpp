w#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

int lbs(int arr[],int n)
{
    int liss[n],ldss[n];
    for(int i=0;i<n;i++)
        liss[i]=ldss[i]=0;

    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
            if(arr[i]>arr[j] && liss[i]<liss[j]+1)
                liss[i]=liss[j]+1;
    for(int i=n-1;i>=0;i--)
        for(int j=i+1;j<n;j++)
            if(arr[i] > arr[j] && ldss[i]<ldss[j]+1)
                ldss[i]=ldss[j]+1;
    int mx=1;
    for(int i=0;i<n;i++)
        if(liss[i]+ldss[i]+1 > mx)
            mx=liss[i]+ldss[i]+1;
    return mx;
}
int main()
{
  int arr[] ={1,9,2,7,11,2,5};
  //{0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LBS is %d\n", lbs( arr, n ) );
  return 0;
}
