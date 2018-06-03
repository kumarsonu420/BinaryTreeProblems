#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

bool modularSum(int arr[],int n,int m)
{
    if(n>m)
        return true;
    bool dp[m];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        if(dp[0])
            return true;
        bool temp[m];
        memset(dp,false,m);
        for(int j=0;j<m;j++)
        {
            if(dp[j])
            {
                if(dp[(j+arr[i])%m]==false)
                    temp[(j+arr[i])%m]=true;
            }
        }
        for(int i=0;i<m;i++)
            if(temp[i])
                dp[i]=true;
        dp[arr[i]%m]=true;
    }
    return dp[0];
}
int main()
{
    int arr[] = {1, 7,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 5;

    modularSum(arr, n, m) ?  cout << "YES\n" :
                             cout << "NO\n";

    return 0;
}
