#include<iostream>
#include<map>
#include<algorithm>
#include <stdio.h>
#include <limits.h>
#include<string.h>
using namespace std;

struct area
{
    int a, b;
    area(int a, int b) : a(a), b(b)
    {}
};

int maxSurvivalTime(int A,int B,area X,area Y,area Z,int loc, map< pair<int,int> ,int>memo)
{
    if(A<=0||B<=0)
        return 0;
    pair<int ,int>curr;
    curr=make_pair(A,B);
    if(memo.find(curr)!=memo.end())
        return memo[curr];
    int res=0;
    switch(loc)
    {
    case 1:
            res= 1 + max(maxSurvivalTime(A+Y.a,B+Y.b,X,Y,Z,2,memo),maxSurvivalTime(A+Z.a,B+Z.b,X,Y,Z,3,memo));
            break;
    case 2:
            res= 1 + max(maxSurvivalTime(A+X.a,B+X.b,X,Y,Z,1,memo),maxSurvivalTime(A+Z.a,B+Z.b,X,Y,Z,3,memo));
            break;
    case 3:
            res= 1 + max(maxSurvivalTime(A+Y.a,B+Y.b,X,Y,Z,2,memo),maxSurvivalTime(A+X.a,B+X.b,X,Y,Z,1,memo));
            break;
    }
    return memo[curr]=res;
}
int getMaxSurvivalTime(int A,int B,area X,area Y,area Z)
{
    if(A<=0||B<=0)
        return 0;
    map< pair<int,int> ,int>memo;

    return max(max(maxSurvivalTime(A+X.a,B+X.b,X,Y,Z,1,memo),
                   maxSurvivalTime(A+Y.a,B+Y.b,X,Y,Z,2,memo)),
                   maxSurvivalTime(A+Z.a,B+Z.b,X,Y,Z,3,memo));

}
int main()
{
    area X(3, 2);
    area Y(-5, -10);
    area Z(-20, 5);

    int A = 20;
    int B = 8;
    cout << getMaxSurvivalTime(A, B, X, Y, Z);

    return 0;
}
