#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int lcs(string x,string y)
{
    int n=x.length();
    int m=y.length();
    int dp[2][m+1]={0};
    for(int i=0;i<=2;i++)
        for(int j=0;j<=m;j++)
            dp[i][j]=0;

    bool bi=0;
    for(int i=1;i<=n;i++)
    {
        bi=i&1;
        for(int j=1;j<=m;j++)
        {
            if(x[i-1]==y[j-1])
                dp[bi][j]=dp[1-bi][j-1]+1;
            else
                dp[bi][j]=max(dp[1-bi][j],dp[bi][j-1]);
        }
    }
    return dp[bi][m];
}
int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    printf("Length of LCS is %d\n", lcs(X, Y));

    return 0;
}
