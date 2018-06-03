#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

void findlcs(string str1,string str2)
{
    int n=str1.length();
    int m=str2.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int i=0;i<=m;i++)
        dp[0][i]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    cout<<dp[n][m]<<endl;
}

void lcs(string str1)
{
    string str2=str1;
    reverse(str2.begin(),str2.end());
    findlcs(str1,str2);
}
int main()
{
    string str = "bbabcbcab";
    lcs(str);
    return 0;
}
