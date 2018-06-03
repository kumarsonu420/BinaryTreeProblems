#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int countWays(int n,int m)
{
    int dp[n+1]={0};
    for(int j=1;j<=n;j++)
    {
        if(j<m)
            dp[j]=1;
        else if(j==m)
            dp[j]=2;
        else
            dp[j]=dp[j-1]+dp[j-m];
    }
    return dp[n];

}
int main()
{
    int n = 2, m = 3;
    cout << "Number of ways = "
         << countWays(n, m);
    return 0;
}
