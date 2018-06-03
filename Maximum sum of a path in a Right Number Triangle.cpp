#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int maxSum(int mat[4][4],int n)
{
    int dp[n][n];
    dp[0][0]=mat[0][0];
    for(int i=1;i<n;i++)
        for(int j=0;j<n;j++)
            if(j==0)
                dp[i][j]=dp[i-1][j]+mat[i][j];
            else if(j==i)
                dp[i][j]=dp[i-1][i-1]+mat[i][j];
            else
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+mat[i][j];
    int mn=0;
    for(int i=0;i<n;i++)
        if(dp[n-1][i]>mn)
            mn=dp[n-1][i];
    return mn;
}
int main()
{
        int tri[4][4] ={ {1},
                            {1 ,2},
                            {4 ,1, 2},
                            {2 ,3 ,1, 1}
                            };

    cout<<maxSum(tri, 4);

    return 0;
}
