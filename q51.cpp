#include<bits/stdc++.h>
using namespace std;

bool isRotation(string s1, string s2)
{
    string temp=s1+s1;
    if(s1.length() != s2.length())
        return false;
    size_t t = temp.find(s2);
    if(t == string::npos)
        return false;
    return true;
}

int main()
{
    string s1 = "qwerty", s2="qewrty";
    cout<<isRotation(s1,s2);
    return 0;
}