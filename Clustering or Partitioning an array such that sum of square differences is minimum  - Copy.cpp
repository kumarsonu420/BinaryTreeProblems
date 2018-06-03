#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#define inf 10000000
using namespace std;

int ans=INT_MAX;
//recursive solution
void solve(int start,int par,int arr[],int n,int k,int curr_ans)
{
    if(par>k)
        return;
    if(par==k && start==n-1)
    {
        ans=min(ans,curr_ans);
        return;
    }
    for(int i=start+1;i<n;i++)
        solve(i,par+1,arr,n,k,curr_ans+(arr[start+1]-arr[i])*(arr[start+1]-arr[i]) );
}

//DP solution
int solveUsingDP(int arr[],int n,int k)
{
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp[i][j]=inf;
    dp[0][0]=0;
    for(int i=1;i<=k;i++)
        for(int j=1;j<=n;j++)
            for(int m=j-1;m>=0;m--)
                dp[j][i]=min(dp[j][i],dp[m][i-1]+(arr[j-1]-arr[m])*(arr[j-1]-arr[m]));

    return dp[n][k];
}
int main()
{
    int k = 2;
    int a[] = {1, 5, 8, 10};
    int n = sizeof(a)/sizeof(a[0]);
    solve(-1, 0, a, n, k, 0);
    cout << ans << endl;
    cout<<solveUsingDP(a,n,k)<<endl;
    return 0;
}
