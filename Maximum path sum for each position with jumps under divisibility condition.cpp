#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;
int printMaxSum(int arr[],int n)
{
    int dp[n];
    memset(dp,0,n);
    for(int i=0;i<n;i++)
    {
        dp[i]=arr[i];
        int mxi=0;
        for(int j=1;j<=sqrt(i+1);j++)
        {
            if((i+1)%j==0 && i+1 != j)
            {
                if(dp[j-1] > mxi)
                    mxi=dp[j-1];
                if(dp[(i+1)/j-1] > mxi && j !=1)
                    mxi=dp[(i+1)/j-1];
            }
        }
        dp[i]+=mxi;
    }
    for(int i=0;i<n;i++)
        cout<<dp[i]<<"  ";
    cout<<endl;
    return 0;
}
int main()
{
    int arr[] = { 2, 3, 1, 4, 6, 5 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxSum(arr, n);
    return 0;
}
