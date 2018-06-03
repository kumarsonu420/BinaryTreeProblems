#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int countEndless( bool mat[4][4] , int n)
{
    bool row[n][n],col[n][n],isendless=true;
    //filling for rows
    for(int i=0;i<n;i++)
    {
        isendless=true;
        for(int j=n-1;j>=0;j--)
        {
            if(mat[i][j]==0)
                isendless=false;
            row[i][j]=isendless;
        }
    }
    //filling column matrix
    for(int j=0;j<n;j++)
    {
        isendless=true;
        for(int i=n-1;i>=0;i--)
        {
            if(mat[i][j]==0)
                isendless=false;
            col[i][j]=isendless;
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(row[i][j] && col[i][j])
                cnt++;
    return cnt;
}

int main()
{
    bool input[][4] = { {1, 0, 1, 1},
                         {0, 1, 1, 1},
                         {1, 1, 1, 1},
                         {0, 1, 1, 0}};
    int n = 4;

    cout << countEndless(input, n);
    return 0;
}
