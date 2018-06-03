#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int maxLoot(int arr[],int n)
{
    int incl=arr[0],excl=0,t;
    for(int i=1;i<n;i++)
    {
        t=incl;
        incl=excl+arr[i];
        excl=max(t,excl);
    }
    return incl;
}
int maxLoot2(int arr[],int n)
{
    int dp[n];
    dp[0]=arr[0];
    dp[1]=arr[1];
    for(int i=2;i<n;i++)
    {
        dp[i]=max(dp[i-2]+arr[i],dp[i-1]);
    }
    return dp[n-1];
}

int main()
{
    int hval[] = {6, 7, 1, 3, 8, 2, 4};
    int n = sizeof(hval)/sizeof(hval[0]);
    cout << "Maximum loot possible : "
        << maxLoot(hval, n)<<endl;
    cout << "Maximum loot possible : "
        << maxLoot2(hval, n);

    return 0;
}

