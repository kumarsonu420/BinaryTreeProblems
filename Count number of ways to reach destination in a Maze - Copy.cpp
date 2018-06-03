#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int countPaths(int maze[4][4],int n,int m)
{
    if(maze[0][0]==-1)
        return -1;
    int dp[n][m];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            dp[i][j]=0;

    for(int i=0;i<n;i++)
        if(maze[i][0]!=-1)
            dp[i][0]=1;
        else
            break;

    for(int i=1;i<m;i++)
        if(maze[0][i]!=-1)
            dp[0][i]=1;
        else
            break;

    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            if(maze[i][j]!=-1)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];

    return dp[n-1][m-1];
}

int main()
{
    int maze[4][4] =  {{0,  0, 0, 0},
                       {0, -1, 0, 0},
                       {-1, 0, 0, 0},
                       {0,  0, 0, 0}};
    cout << countPaths(maze,4,4);
    return 0;
}
