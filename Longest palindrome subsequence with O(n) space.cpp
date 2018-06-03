#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

int lps( char *str )
{
    int n=strlen(str);
    int dp[n];
    for(int i=0;i<n;i++)
        dp[i]=1;
    for(int i=n-1;i>=0;i--)
    {
        int backup=0;


        for(int j=i+1;j<n;j++)
        {
            if(str[i]==str[j])
            {
                int t=dp[j];
                dp[j]=backup +2;
                backup=t;
            }
            else
            {
                backup=dp[j];
                dp[j]=max(dp[j-1],dp[j]);
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<dp[i]<<"   ";
    cout<<endl;
    return dp[n-1];
}
int main()
{
    char str[] = "geeksforgeeks";
    cout << lps(str);
    return 0;
}
