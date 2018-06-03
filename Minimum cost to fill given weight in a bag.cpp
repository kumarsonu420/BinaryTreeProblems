#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;
int MinimumCost(int c[],int n,int w)
{
    vector<int>cost,weight;
    for(int i=0;i<n;i++)
        if(c[i]!=-1)
        {
            cost.push_back(c[i]);
            weight.push_back(i+1);
        }
    n=cost.size();
    int dp[n+1][w+1];
    for(int i=0;i<=w;i++)
        dp[0][i]=10000;
    for(int i=1;i<=n;i++)
        dp[i][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(weight[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=min(dp[i-1][j],cost[i-1]+dp[i][j-weight[i-1]]);
        }
    }
    return (dp[n][w]==10000? -1 :dp[n][w]);
}
int main()
{
    int cost[] =  {-1, -1, 4, 5, -1}, W = 5;
    int n = sizeof(cost)/sizeof(cost[0]);
    cout << MinimumCost(cost, n, W);
    return 0;
}
