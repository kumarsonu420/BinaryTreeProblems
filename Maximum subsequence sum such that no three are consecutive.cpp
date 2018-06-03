#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int maxSumWO3Consec(int arr[],int n)
{
    int dp[n];
    dp[0]=arr[0];
    dp[1]=arr[0]+arr[1];
    dp[2]=max(max(dp[1],arr[0]+arr[2]),arr[1]+arr[2]);
    for(int i=3;i<n;i++)
    {
        dp[i]=max(dp[i-1],max(dp[i-2]+arr[i],dp[i-3]+arr[i]+arr[i-1]));
    }
    return dp[n-1];
}
int main()
{
    int arr[] = {100, 1000, 100, 1000, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxSumWO3Consec(arr, n);
    return 0;
}
