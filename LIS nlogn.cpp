#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string.h>
#include <limits.h>
using namespace std;
int ceilIndex(vector<int>&vec,int l,int h,int key)
{
    while(h-l > 1)
    {
        int m=l+(h-l)/2;
        if(vec[m]>=key)
            h=m;
        else
            l=m;
    }
    return h;
}
int lis(int arr[],int n)
{
    vector<int>vec(n,0);
    vec[0]=arr[0];
    int length=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]<vec[0])
            vec[0]=arr[i];
        else if(arr[i]>vec[length-1])
            vec[length++]=arr[i];
        else
            vec[ceilIndex(vec,0,length-1,arr[i])]=arr[i];
    }
    return length;
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d",lis( arr, n ));
    return 0;
}
