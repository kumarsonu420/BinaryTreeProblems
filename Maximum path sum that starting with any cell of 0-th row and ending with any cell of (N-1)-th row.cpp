#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;
int MaximumPath ( int mat[4][4] )
{
    int n,m;
    n=m=4;
    int dp[n][m];
    for(int i=0;i<n;i++)
        dp[0][i]=mat[0][i];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j==0)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+mat[i][j];
            else if(j==m-1)
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+mat[i][j];
            else
                dp[i][j]=max(max(dp[i-1][j-1],dp[i-1][j+1]),dp[i-1][j])+mat[i][j];
        }
    }
    int mx=INT_MIN;
    for(int i=0;i<m;i++)
        if(dp[n-1][iw]>mx)
            mx=dp[n-1][i];
    return mx;
}
int main()
{
    int Mat[4][4] = { { 4, 2 , 3 , 4 },
        { 2 , 9 , 1 , 10},
        { 15, 1 , 3 , 0 },
        { 16 ,92, 41, 44 }
    };

    cout << MaximumPath ( Mat ) <<endl ;
    return 0;
}
