#include<bits/stdc++.h>
#include<iostream>
#include<unordered_map>
using namespace std;

int  longestUniqueSubsttr(char *str)
{
    unordered_map<char,int>mp;
    int mxlen=1,len=0;
    for(int i=0;i<strlen(str);i++)
    {
        mp[str[i]]++;
        if(mp[str[i]]==1)
            len++;
        else
        {
            if(len>mxlen)
                mxlen=len;
            len=0;
            mp.clear();
        }
    }
    return mxlen;
}
int main()
{
    char str[] =  "GEEKSFORGEEKS";
    printf("The input string is %s n", str);
    int len =  longestUniqueSubsttr(str);
    printf("The length of the longest non-repeating "
           "character substring is %d", len);
    return 0;
}

