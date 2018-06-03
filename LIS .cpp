#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int lis(int arr[],int n)
{
    int l[n];
    for(int i=0;i<n;i++)
        l[i]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j]&&l[i]<l[j]+1)
                l[i]=l[j]+1;
        }

    }
    return *max_element(l,l+n);
}
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d", lis( arr, n ) );
    return 0;
}
