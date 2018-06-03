#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

int longestPalSubstr( string str )
{
    int n=str.length();
    bool dp[n][n];
    memset(dp,0,n*n);
    int mxlen=1;
    //for substring of length 1
    for(int i=0;i<n;i++)
        dp[i][i]=true;
    //for substring of length 2
    for(int i=0;i<n-1;i++)
        if(str[i]==str[i+1])
            dp[i][i+1]=true;
    int start=0;
    for(int times=2;times<n;times++)
    {
        int j=times;
        for(int i=0;i<n-times;i++)
        {
            if(dp[i+1][j-1] && str[i]==str[j])
            {
                dp[i][j]=true;
                if(times+1>mxlen)
                {
                    mxlen=times+1;
                    start=i;
                }
            }
            j++;
        }
    }
    string s=str.substr(start,mxlen );
    cout<<s<<endl;
    return mxlen;
}
int main()
{
    char str[] ="forgeeksskeegfor";
    printf("nLength is: %d ", longestPalSubstr( str ) );
    cout<<endl;
    return 0;
}
