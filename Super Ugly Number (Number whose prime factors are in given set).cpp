#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

int superUgly(int n,int primes[],int k)
{
    int su[n];
    int multiply[n];
    int uglycnt=1,no=1;
    for(int i=0;i<n;i++)
    {
        su[i]=primes[i];
        multiply[i]=1;
    }
    while(uglycnt<k)
    {
        no=*min_element(su,su+n);
        //cout<<no<<"  ";
        for(int i=0;i<n;i++)
            if(su[i]==no)
            {
                multiply[i]++;
                su[i]=primes[i]*multiply[i];
            }
        uglycnt++;
    }
    return no;
}
int main()
{
    int primes[] = {2,3, 5};
    int n= sizeof(primes)/sizeof(primes[0]);
    int k = 50;
    cout << superUgly(n, primes, k);
    return 0;
}
