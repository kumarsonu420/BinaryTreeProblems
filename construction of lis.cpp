#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string.h>
#include <limits.h>
using namespace std;
void print(vector<int>vec)
{
    for(int i:vec)
        cout<<i<<" ";
    cout<<endl;
}
void construct_lis(int arr[],int n)
{
    vector< vector<int> >vec(n);
    vec[0].push_back(arr[0]);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
            if(arr[j]<arr[i] && vec[i].size() < vec[j].size()+1)
                vec[i]=vec[j];

        vec[i].push_back(arr[i]);
    }

    vector<int>v=vec[0];
    for(vector<int> ve:vec)
        if(v.size()< ve.size())
            v=ve;
    print(v);
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    construct_lis(arr,n);
    return 0;
}
