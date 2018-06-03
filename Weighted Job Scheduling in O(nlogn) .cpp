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
int binarySearch(Job jobs[], int index)
{
    int lo = 0, hi = index - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
    return -1;
}

int latestNonConflict(Job arr[],int l,int h,int time)
{
    while(l<h)
    {
        int m=(l+h)/2;
        if(arr[m].stop<time)
            h=m;
        else
            l=m;
    }
    if(arr[h].stop<time)
        return h;
    return -1;
}

int findMaxProfit(Job arr[],int n)
{
    sort(arr,arr+n,myComp);
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=arr[i].profit;
    for(int i=1;i<n;i++)
    {
        int p=latestNonConflict(arr,0, i-1,arr[i].start);
        //int p=binarysearch(arr,i);
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
    cout << "The optimal profit is " << findMaxProfit(arr, n)<<endl;
    return 0;
}
