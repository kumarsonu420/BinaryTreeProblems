#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int binomialCoeff(int n,int k)
{
    if(n-k < k)
        k=n-k;
    int res=1;
    for(int i=0;i<k;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
int catalanDP(int k)
{
    if(k==1)
        return k;
    return binomialCoeff(2*k,k)/(k+1);
}
int main()
{
    cout<<catalanDP(10)<<endl;
    return 0;
}

