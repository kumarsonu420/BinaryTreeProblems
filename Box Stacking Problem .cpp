#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

struct Box
{
    int h,w,d;
};

bool myComp(Box X,Box Y)
{
    return (X.w*X.d - Y.w*Y.d < 0);
}

int maxStackHeight(Box arr[],int n)
{
    Box a[n*3];
    int index=0;
    for(int i=0;i<n;i++)
    {
        a[index].h=arr[i].h;
        a[index].w=arr[i].w;
        a[index].d=arr[i].d;
        index++;
        //keeping the width small just for simplicity
        a[index].h=arr[i].w;
        a[index].w=min(arr[i].h,arr[i].d);
        a[index].d=max(arr[i].h,arr[i].d);
        index++;

        a[index].h=arr[i].d;
        a[index].w=min(arr[i].h,arr[i].w);
        a[index].d=max(arr[i].h,arr[i].w);
        index++;
    }
    n=n*3;
    sort(a,a+n,myComp);

    for(int i=0;i<n;i++)
        cout<<"("<<a[i].h<<"  "<<a[i].w<<"  "<<a[i].d<<")"<<endl;

    int lis[n];
    for(int i=0;i<n;i++)
        lis[i]=0;
    lis[0]=a[0].h;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[j].d < a[i].d && a[j].w < a[i].w && lis[j]+a[i].h > lis[i])
                lis[i]=lis[j] + a[i].h;

    int mx=0;
    for(int i=0;i<n;i++)
        if(lis[i]>mx)
            mx=lis[i];
    return mx;
}

int main()
{
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("The maximum possible height of stack is %d\n",
         maxStackHeight (arr, n) );

  return 0;
}
