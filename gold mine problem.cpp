#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;
int getMaxGold(int mat[4][4],int n ,int m)
{
    int dp[n][m];
    for(int i=0;i<n;i++)
        dp[i][0]=mat[i][0];
    for(int col=1;col<m;col++)
    {
        for(int row=0;row<n;row++)
        {
            if(row==0)
                dp[row][col]=max(dp[row][col-1],dp[row+1][col-1])+mat[row][col];
            else if(row==n-1)
                dp[row][col]=max(dp[row-1][col-1],dp[row][col-1])+mat[row][col];
            else
                dp[row][col]=max(max(dp[row][col-1],dp[row+1][col-1]),dp[row-1][col-1])+mat[row][col];
        }
    }
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
        if(dp[i][m-1]>mx)
            mx=dp[i][m-1];
    return mx;
}
int main()
{
    int gold[4][4]= {   {1, 3, 1, 5},
                            {2, 2, 4, 1},
                            {5, 0, 2, 3},
                            {0, 6, 1, 2}
                                            };
    int m = 4, n = 4;
    cout << getMaxGold(gold, m, n);
    return 0;
}
