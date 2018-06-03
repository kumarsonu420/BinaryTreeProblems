#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

struct Job
{
    int start;
    int stop;
    int profit;
};

bool myComp(Job a,Job b)
{
    return (a.stop < b.stop);
}
int findMaxProfit(Job arr[],int n)
{
    sort(arr,arr+n,myComp);
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=arr[i].profit;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j].stop<=arr[i].start && dp[j]+arr[i].profit>dp[i])
                dp[i]=dp[j]+arr[i].profit;
        }
    }
    return dp[n-1];
}
int main()
{
    Job arr[] = { {6, 19, 100}, {20, 100, 200},{3, 10, 20}, {1, 2, 50} };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxProfit(arr, n);
    return 0;
}
