# include<bits/stdc++.h>
using namespace std;

int getNthUglyNo(int n)
{
    int a[n];
    a[0]=1;
    int i2=0,i3=0,i5=0;
    int nextuglyno,ugly2=2,ugly3=3,ugly5=5;
    for(int i=1;i<n;i++)
    {
        nextuglyno=min(ugly2,min(ugly3,ugly5));
        a[i]=nextuglyno;
        if(nextuglyno==ugly2)
        {
            i2+=1;
            ugly2=a[i2]*2;
        }
        if(nextuglyno==ugly3)
        {
            i3+=1;
            ugly3=a[i3]*3;
        }
        if(nextuglyno==ugly5)
        {
            i5+=1;
            ugly5=a[i5]*5;
        }
    }
    return a[n-1];

}
int main()
{
    int n = 150;
    cout << getNthUglyNo(n);
    return 0;
}
