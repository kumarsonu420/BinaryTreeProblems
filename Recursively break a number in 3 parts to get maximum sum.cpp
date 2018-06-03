#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int breakSum(int n)
{
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
        dp[i]=max((dp[i/2]+dp[i/3]+dp[i/4]),i);
    return dp[n];
}
int main()
{
    int n = 24;
    cout << breakSum(n);
    return 0;
}
