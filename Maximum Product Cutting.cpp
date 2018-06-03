#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

int maxProd(int n)
{
    if(n==2 || n==3)
        return n-1;
    int dp[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=0;
        if(i<4)
            dp[i]=i;
        else
            for(int j=1;j<=i/2;j++)
                dp[i]=max(dp[i],dp[i-j]*j);
    }
    return dp[n];
}
// A Dynamic Programming solution for Max Product Problem
int maxProd2(int n)
{
   int val[n+1];
   val[0] = val[1] = 0;

   // Build the table val[] in bottom up manner and return
   // the last entry from the table
   for (int i = 1; i <= n; i++)
   {
      int max_val = 0;
      for (int j = 1; j <= i/2; j++)
         //max_val = max(max_val, (i-j)*j, j*val[i-j]);
      val[i] = max_val;
   }
   return val[n];
}
int maxProd1(int n)
{
   // n equals to 2 or 3 must be handled explicitly
   if (n == 2 || n == 3) return (n-1);

   // Keep removing parts of size 3 while n is greater than 4
   int res = 1;
   while (n > 4)
   {
       n -= 3;
       res *= 3; // Keep multiplying 3 to res
   }
   return (n * res); // The last part multiplied by previous parts
}
int mProd(int n)
{
    if(n==2 || n==3)
        return n-1;
    int times=(n-2)/3;
    int res=pow(3,times);
    res=res*( (n-2)%3 + 2);
}
int main()
{
    cout << "Maximum Product is " << maxProd(10);
    int n;
    cin>>n;
    cout << "Maximum Product is " << mProd(n);
    cout << "Maximum Product is " << maxProd1(10);
    return 0;
}
