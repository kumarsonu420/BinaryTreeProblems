#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int numOfIncSubseqOfSizeK(int arr[], int n, int k)
{
    int dp[k][n]={0};
    for(int i=0;i<n;i++)
        dp[0][i]=1;

    for(int i=1;i<k;i++)
    {
        for(int j=i;j<n;j++)
        {
            for(int l=i-1;l<j;l++)
                if(arr[l]<arr[j])
                    dp[i][j]+=dp[i-1][l];
        }
    }
    int tot=0;;
    for(int i=k-1;i<n;i++)
        tot+=dp[k-1][i];
    return tot;
}
int main()
{
    int arr[] = { 12, 8, 11, 13, 10, 15, 14, 16, 20 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    cout << "Number of Increasing Subsequences of size "
         << k << " = " << numOfIncSubseqOfSizeK(arr, n, k);

    return 0;
}
