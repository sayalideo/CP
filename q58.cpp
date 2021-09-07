//Split the Binary string into two substring with equal 0’s and 1’s

#include<bits/stdc++.h>
using namespace std;

int countEqual(string s)
{
    int count=0,z=0,o=0,i;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='0')
            z++;
        else
            o++;
        if(z==o)
            count++;
        
    }
    if(count==0)
        return -1;
    return count;

}

int main()
{
    string s = "0111100010";
    cout<<countEqual(s);
}