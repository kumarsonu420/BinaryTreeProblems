#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int maxSumPairWithDifferenceLessThanK2(int arr[], int N, int k)
{
    int maxSum = 0;
    sort(arr, arr+N);
    for (int i=N-1; i>0; --i)
        if (arr[i]-arr[i-1] < k)
        {
            maxSum += arr[i];
            maxSum += arr[i-1];
            --i;
        }
    return maxSum;
}
int maxSumPairWithDifferenceLessThanK(int arr[],int n,int k)
{
    int dp[n];
    sort(arr,arr+n);
    dp[0]=0;
    if(arr[1]-arr[0]<k)
        dp[1]=arr[0]+arr[1];
    else
        dp[1]=0;
    for(int i=2;i<n;i++)
    {
        dp[i]=dp[i-1];
        if(arr[i]-arr[i-1]<k)
            dp[i]=max((dp[i-2]+arr[i-1]+arr[i]),dp[i]);
    }
    return dp[n-1];
}
int main()
{
    int arr[] = {3, 5, 10, 15, 17, 12, 9};
    int N = sizeof(arr)/sizeof(int);

    int K = 4;
    cout << maxSumPairWithDifferenceLessThanK(arr, N, K)<<endl;
    cout << maxSumPairWithDifferenceLessThanK2(arr, N, K)<<endl;
    return 0;
}
