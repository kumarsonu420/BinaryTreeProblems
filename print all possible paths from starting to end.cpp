#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

void justprint(int mat[4][4],int n,int m,int path[],int i,int j,int pi)
{
    if(i==n-1)
    {
        for(int k=j;k<m;k++)
            path[pi+k-j]=mat[i][k];
        for(int  k=0;k<pi+m-j;k++)
            cout<<path[k]<<"  ";
        cout<<endl;
        return ;
    }
    if(j==m-1)
    {
        for(int k=i;k<n;k++)
            path[pi+k-i]=mat[k][j];
        for(int k=0;k<pi+n-i;k++)
            cout<<path[k]<<"  ";
        cout<<endl;
        return ;
    }

    path[pi]=mat[i][j];
    justprint(mat,n,m,path,i+1,j,pi+1);
    justprint(mat,n,m,path,i,j+1,pi+1);
}
void printAllPaths(int mat[4][4],int n,int m)
{
    int path[n+m];
    justprint(mat,n,m,path,0,0,0);
}

int main()
{
    int mat[4][4] = {1, 2, 3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    printAllPaths(mat,4,4);
    return 0;
}

