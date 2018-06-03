#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

int findLcs(string str1,string str2,int n)
{
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return (n - dp[n][n]);
}
int findMinInsertionsDP(string str,int n)
{
    string strr=str;
    reverse(str.begin(),str.end());
    return findLcs(str,strr,n);
}
int lps( string str )
{
    int n=str.length();
    int dp[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=0;

    for(int i=0;i<n;i++)
    {
        int k=0;
        for(int j=i;j<n;j++)
        {
            if(k==j)
                dp[k][j]=1;
            else if(str[k]==str[j])
                dp[k][j]=dp[k+1][j-1]+2;
            else
                dp[k][j]=max(dp[k+1][j],dp[k][j-1]);
            k++;
        }
    }
    return dp[0][n-1];
}

int main()
{
    string str = "geeksforgeeks";
    int n=str.length();
    //method 1 using  (length - longest common subsequence)
    printf("%d", findMinInsertionsDP(str, n) );
    //method 2 using  (length - longest palindromic subsequence)
    cout<<endl<<n-lps(str)<<endl;
    return 0;
}
