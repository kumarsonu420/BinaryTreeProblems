#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

int lookup[100][100];
int recursivelyCountSeq(int n,int diff)
{
    if(abs(diff)>n)
        return 0;
    if(n==1&&diff==0)
        return 2;
    if(n==1&&abs(diff)==1)
        return 1;

    return (recursivelyCountSeq(n-1,diff-1)+
            2*recursivelyCountSeq(n-1,diff)+
            recursivelyCountSeq(n-1,diff+1));
}
int countSeq(int n,int diff)
{
    if(abs(diff)>n)
        return 0;
    if(n==1&&diff==0)
        return 2;
    if(n==1&&abs(diff)==1)
        return 1;
    if(lookup[n][n+diff]!=-1)
        return lookup[n][n+diff];

    int res=(recursivelyCountSeq(n-1,diff-1)+
            2*recursivelyCountSeq(n-1,diff)+
            recursivelyCountSeq(n-1,diff+1));

    return lookup[n][n+diff]=res;
}
int binomialCountSeq(int n)
{
    int ncr=1,ncrsum=1;
    for(int i=1;i<=n;i++)
    {
        ncr=ncr*(n+1-i)/i;
        ncrsum+=ncr*ncr;
    }
    return ncrsum;
}
int main()
{
    int n ;
    cin>>n;
    cout << "Count of sequences is "
         << recursivelyCountSeq(n, 0)<<endl;
    memset(lookup,-1,sizeof(lookup));

    cout << "Count of sequences is "
         << countSeq(n, 0)<<endl;

    cout << "Count of sequences is "
         << binomialCountSeq(n)<<endl;

    return 0;
}
