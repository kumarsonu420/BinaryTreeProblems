#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int countP(int n,int k)
{
    if(k==1 || k==n)
        return 1;
    if(k>n)
        return 0;
    int dp[n][k];
    for(int i=0;i<n;i++)
        dp[0][i]=0;
    for(int i=0;i<n;i++)
        dp[i][0]=1;

    for(int i=1;i<n;i++)
        for(int j=1;j<k;j++)
            dp[i][j]=dp[i-1][j-1] +(j+1)*dp[i-1][j];

    return dp[n-1][k-1];
}
int main()
{
   cout <<  countP(3, 2);
   return 0;
}
