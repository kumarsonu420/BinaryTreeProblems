#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#define inf 10000000
using namespace std;

int ans=INT_MIN;
void maxDecimalValue(int mat[][4],int n,int m,int curr_ans)
{
    if(n<0 || m<0)
        return;
    if(n==0 && m==0)
    {
        ans=max(ans,curr_ans+mat[0][0]);
        return;
    }
    maxDecimalValue(mat,n-1,m,curr_ans+ (mat[n][m]<<(n+m)) );
    maxDecimalValue(mat,n,m-1,curr_ans+ (mat[n][m]<<(n+m)) );
}
int main()
{
    int mat[][4] = {{ 1 ,1 ,0 ,1 },
                    { 0 ,1 ,1 ,0 },
                    { 1 ,0 ,0 ,1 },
                    { 1 ,0 ,1 ,1 },
                                    };
    maxDecimalValue(mat,3,3,0);
    cout<<ans<< endl;
    return 0;
}
