#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;

int longestPalSubstr(string str )
{
    int len=str.length();
    int low,high,maxLength=0,start=0;
    for (int i = 1; i < len; ++i)
    {
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            if (high - low + 1 > maxLength)
            {
                start = low;
                maxLength = high - low + 1;
            }
            --low;
            ++high;
        }
    }
 string s=str.substr(start,maxLength);
    cout<<s<<endl;
    return maxLength;
}
int main()
{
    char str[] = "forgeeksskeegfor";
    printf("nLength is: %d ", longestPalSubstr( str ) );
    return 0;
}
