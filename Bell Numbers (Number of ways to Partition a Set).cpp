#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;
int lookup[100][100];
void bellNumber(int n)
{
    lookup[0][0]=1;
    for(int i=1;i<n;i++)
        for(int j=0;j<=i;j++)
        {
            if(j==0)
                lookup[i][j]=lookup[i-1][i-1];
            else
                lookup[i][j]=lookup[i-1][j-1]+lookup[i][j-1];
        }
}
int main()
{
    int n;
    cin>>n;
    memset(lookup,0,sizeof(lookup));
    bellNumber(n);
    for (int i=0; i<n; i++)
         cout<<lookup[i][0]<< "   ";
     cout<<endl;
    return 0;
}
