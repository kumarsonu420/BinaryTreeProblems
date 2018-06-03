#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

bool dp[100][100];
void display(const vector<int>& v)
{
    for (int i :v)
        cout<<i<<" ";
    printf("\n");
}
void printAllPaths(int arr[],int i,int sum,vector<int>&store)
{
    if(i==0  && sum!=0 && dp[0][sum] )
    {
        store.push_back(arr[i]);
        display(store);
        return;
    }
    if(i==0 && sum==0)
    {
       display(store);
       return;
    }
    //ignoring the current element
    if(dp[i-1][sum])
    {
        vector<int>p=store;
        printAllPaths(arr,i-1,sum,p);
    }
    //including current element
    if( sum >= arr[i] && dp[i-1][sum-arr[i]])
    {
        store.push_back(arr[i]);
        printAllPaths(arr,i-1,sum-arr[i],store);
    }

}
void printAllSubsets(int arr[],int n,int sum)
{
    if (n == 0 || sum < 0)
       return;
    memset(dp,false,sizeof(dp));

    for(int i=0;i<n;i++)
        dp[i][0]=true;
    if (arr[0] <= sum)
       dp[0][arr[0]] = true;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(j < arr[i])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i]];

        }
    }
    if (dp[n-1][sum] == false)
    {
        printf("There are no subsets with sum %d\n", sum);
        return;
    }

    vector<int> store;
    printAllPaths(arr,n-1,sum,store);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 10;
    printAllSubsets(arr, n, sum);
    return 0;
}
