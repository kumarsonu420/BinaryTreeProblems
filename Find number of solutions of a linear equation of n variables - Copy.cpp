#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int countSol(int coeff[],int n ,int rhs)
{
    int dp[rhs+1]={0};
    dp[0]=1;
    for(int i=0;i<n;i++)
        for(int j=coeff[i];j<=rhs;j++)
            dp[j]+=dp[j-coeff[i]];
    return dp[rhs];
}

int main()
{
    int coeff[]  = {2, 2, 5};
    int rhs = 4;
    int n = sizeof(coeff)/sizeof(coeff[0]);
    cout << countSol(coeff, n, rhs);
    return 0;
}
