#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int MaxSumBS(int arr[],int n)
{
    int msiss[n],msdss[n],a[n];
    for(int i=0;i<n;i++)
        msiss[i]=msdss[i]=arr[i];

    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(arr[j]<arr[i]&&msiss[i]<msiss[j]+arr[i])
                msiss[i]=msiss[j]+arr[i];

    for(int i=n-2;i>=0;i--)
        for(int j=n-1;j>i;j--)
            if(arr[j]<arr[i]&&msdss[i]<msdss[j]+arr[i])
                msdss[i]=msdss[j]+arr[i];

    int mxsum=INT_MIN;
    for(int i=0;i<n;i++)
        mxsum=max(mxsum,msiss[i]+msdss[i]-arr[i]);
    return mxsum;
}
int main()
{
    int arr[]=  {80, 60, 30, 40, 20, 10} ;
    int  n = sizeof(arr)/sizeof(arr[0]);
    cout << "Maximum Sum : " << MaxSumBS(arr, n);

    return 0;
}
