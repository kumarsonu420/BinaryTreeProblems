#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;
int getMinSteps(int n)
{
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        if(i<=3)
            dp[i]=1;
        else
        {
            int by2=(i%2==0)?dp[i/2]:INT_MAX;

            int by3=(i%3==0)?dp[i/3]:INT_MAX;
            dp[i]=1+min(dp[i-1],min(by2,by3));
        }
    }
    return dp[n];
}
int main()
{
    int n ;
    cin>>n;
    cout << getMinSteps(n);
    return 0;
}
