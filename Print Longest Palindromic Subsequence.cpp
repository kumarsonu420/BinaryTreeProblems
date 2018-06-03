#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

void lcs( char *X, char *Y, int m, int n )
{
   int L[m+1][n+1];

   /* Following steps build L[m+1][n+1] in bottom up fashion. Note
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }

   // Following code is used to print LCS
   int index = L[m][n];

   // Create a character array to store the lcs string
   char lcs[index+1];
   lcs[index] = '\0'; // Set the terminating character

   // Start from the right-most-bottom-most corner and
   // one by one store characters in lcs[]
   int i = m, j = n;
   while (i > 0 && j > 0)
   {
      // If current character in X[] and Y are same, then
      // current character is part of LCS
      if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }

      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
   }

   // Print the lcs
   cout << "LCS of " << X << " and " << Y << " is " << lcs;
}
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
    for(int i=0;i<=n;i++)
        {for(int j=0;j<=m;j++)
        cout<<dp[i][j]<<"  ";
    cout<<endl;}
    string res="";
    int i=n,j=m;
    while( dp[i][j] )
    {

        if((dp[i-1][j-1]+1)==dp[i][j])
        {
            res+=str1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]==dp[i][j])
            i--;
        else
            j--;
    }
    cout<<res;
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
