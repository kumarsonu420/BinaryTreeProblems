#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;
struct pairs
{
    int a,b;
};
bool compare(pairs x,pairs y)
{
    if(x.a < y.b)
        return true;
    return false;
}
int lis(struct pairs obj[],int n)
{
    sort(obj,obj+n,compare);
    int l[n],cnt=0;
    for(int i=0;i<n;i++)
        l[i]=1;

    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(obj[i].a>obj[j].b&&l[i]<=l[j])
                l[i]=l[j]+1;

    return *max_element(l,l+n);
}
int main(){
    //int arr[] ={10,22,9,33,21,50,41,60};
    int n;
    cin>>n;
    struct pairs obj[n];
    //int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
        cin>>obj[i].a>>obj[i].b;
    printf("Length of lis is %d", lis(obj,n) );
    return 0;
}

