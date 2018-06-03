#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

void catalanDP(int k)
{
    if(k==1)
    {
        cout<<k;
        return ;
    }
    int dp[k],cat=0;
    for(int i=0;i<k;i++)
        dp[i]=0;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=k;i++)
        for(int j=0;j<i;j++)
            dp[i]+=dp[j]*dp[i-1-j];
    for(int i=0;i<k;i++)
        cout<<dp[i]<<"   ";
}
int main()
{
    catalanDP(10);
    return 0;
}

