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
        dp[i]=max(dp[i-1],dp[i]);
    }
    return dp[n-1];
}

int latestNonConflict(Job arr[],int n,int time,int k)
{
    for(int i=k;i>=0;i--)
        if(arr[i].stop<=time)
            return i;
    return -1;
}

int findMaxProfit1(Job arr[],int n)
{
    sort(arr,arr+n,myComp);
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=arr[i].profit;
    for(int i=1;i<n;i++)
    {
        int p=latestNonConflict(arr,n,arr[i].start,i-1);
        if(p!=-1)
            dp[i]=dp[p]+arr[i].profit;
        else
            dp[i]=max(dp[i-1],dp[i]);
    }
    return dp[n-1];
}

int main()
{
    Job arr[] = { {6, 19, 100},{3, 10, 20}, {1, 2, 50}, {1, 100, 1} };
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << findMaxProfit(arr, n);
    cout<<endl<<"2nd method: "<<endl;
    cout << "The optimal profit is " << findMaxProfit1(arr, n)<<endl;
    return 0;
}
