#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int knapSack(int w,int wt[],int val[],int n)
{
    int dp[n+1][w+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++)
        for(int j=1;j<=w;j++)
        {
            if(wt[i-1] <=w)
                dp[i][j]=max(dp[i-1][j-wt[i-1]]+val[i-1],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];
        }
    return dp[n][w];
}
int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
