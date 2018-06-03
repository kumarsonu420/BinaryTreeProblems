#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

vector<int> longestBitonicSubseq(int arr[],int n)
{
    vector<vector<int> >vec(n);
    vec[0].push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
            if(arr[i]>arr[j]&&vec[i].size()<vec[j].size()+1)
                vec[i]=vec[j];
        vec[i].push_back(arr[i]);
    }
    vector<int>mx=vec[0];
    for(vector<int>v:vec)
        if(v.size()>mx.size())
            mx=v;
    return mx;
}
int longestBitonic(int arr1[], int n1, int arr2[],int n2)
{
    vector<int>inc=longestBitonicSubseq(arr1,n1);
    reverse(arr2,arr2+n2);
    vector<int>dec=longestBitonicSubseq(arr2,n2);
    reverse(dec.begin(),dec.end());
    for(int i:inc)
        cout<<i<<"  ";
    for(int i:dec)
        cout<<i<<"  ";
    cout<<endl;
}
int main()
{
    int arr1[] = { 1, 2, 3, 4 };
    int arr2[] = { 8, 9,7,6,5,4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    longestBitonic(arr1, n1, arr2, n2);
    return 0;
}
