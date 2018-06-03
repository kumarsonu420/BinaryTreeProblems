#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <list>
#include <limits.h>
#include<string.h>
#define M 4
#define N 4

using namespace std;

struct Point
{
    int x, y;
};
list<Point> printPath(int mat[M][N],int dp[M][N],int row,int col)
{
    list<Point>l;

    Point p={row,col};
    l.push_front(p);
    while(dp[row][col]!=0)
    {
        if(row>0 && dp[row-1][col]==dp[row][col]+1)
        {
            p={row-1,col};
            l.push_front(p);
            row--;
        }
        else if(col>0 && dp[row][col-1]==dp[row][col]+1)
        {
            p={row,col-1};
            l.push_front(p);
            col--;
        }
        else{}
    }
    return l;
}

void findSnakeSequence(int mat[M][N])
{
    int dp[N][M];
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            dp[i][j]=0;

    int row=0,col=0;
    for(int i=1;i<N;i++)
        if(abs(dp[0][i]-dp[0][i-1])==1)
            dp[0][i]=1+dp[0][i-1];
    for(int i=1;i<M;i++)
        if(abs(dp[i][0]-dp[i-1][0])==1)
            dp[i][0]=1+dp[i-1][0];

    for(int i=1;i<M;i++)
    {
        for(int j=1;j<N;j++)
        {
            if( abs(mat[i][j]-mat[i-1][j])==1)
            {
                dp[i][j]=dp[i-1][j]+1;
                row=i;
                col=j;
            }
            if(abs(mat[i][j]-mat[i][j-1])==1)
            {
                dp[i][j]=max(dp[i][j-1]+1,dp[i][j]);
                row=i;
                col=j;
            }
        }
    }
    list<Point>path=printPath(mat,dp,row,col);
    for(auto it=path.begin();it!=path.end();it++)
    {
        cout<<mat[it->x][it->y];
        cout<<"("<<it->x<<" , "<<it->y<<")"<<endl;
    }
}
int main()
{
    int mat[M][N] =
    {
        {9, 6, 5, 2},
        {8, 7, 6, 5},
        {7, 3, 1, 6},
        {1, 1, 1, 7},
    };
    findSnakeSequence(mat);
    return 0;
}
