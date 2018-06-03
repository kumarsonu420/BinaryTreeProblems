#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
int lps(char *seq, int i, int j)
{
   // Base Case 1: If there is only 1 character
   if (i == j)
     return 1;

   // Base Case 2: If there are only 2 characters and both are same
   if (seq[i] == seq[j] && i + 1 == j)
     return 2;

   // If the first and last characters match
   if (seq[i] == seq[j])
      return lps (seq, i+1, j-1) + 2;

   // If the first and last characters do not match
   return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}

int lps( char *str )
{
    int n=strlen(str);
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
    for(int i=0;i<n;i++)
        {for(int j=0;j<n;j++)
            cout<<dp[i][j]<<"  ";
        cout<<endl;}
    return dp[0][n-1];
}
int main()
{
    char seq[] = "BBABCBCAB";
    printf ("The lnegth of the LPS is %d", lps(seq));
    cout<<endl<<lps(seq,0,strlen(seq)-1);
    return 0;
}
