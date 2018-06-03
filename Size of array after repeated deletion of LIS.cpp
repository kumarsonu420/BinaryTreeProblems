#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

vector<int> findlis(vector<int>arr,int n)
{
    vector< vector<int> >L(n);
    L[0].push_back(arr[0]);

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j] < arr[i] )
                L[i]=L[j];
        }
        L[i].push_back(arr[i]);
    }
    vector<int>mx;
    for(vector<int> v: L)
        if(mx.size() < v.size())
            mx=v;
    return mx;
}
int minimize(int input[],int n)
{
    vector<int>arr(input,input+n);
    while(arr.size())
    {
        vector<int>lis=findlis(arr,n);

        if(lis.size() < 2)
            break;

        for(int i=0;i<arr.size() && lis.size()>0 ;i++)
            if(arr[i]==lis[0])
            {
                i--;
                lis.erase(lis.begin());
                arr.erase(arr.begin()+i);
            }
    }
    if(arr.size()!=0)
        for(int i=0;i<arr.size();i++)
            cout<<arr[i]<<"  ";
    else
        return 0;
}
int main()
{
    int input[] = {5, 3, 2};
    int n = sizeof(input) / sizeof(input[0]);
    cout<<endl;
    cout<<minimize(input, n)<<endl;
    return 0;
}
