// https://practice.geeksforgeeks.org/problems/roman-number-to-integer/0 
// Initial template for C++

// Program to convert Roman Numerals to Numbers
#include <bits/stdc++.h>
using namespace std;

// Returns decimal value of roman numaral
int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}// } Driver Code Ends


// User fuunction teemplate for C++

// str given roman number string
// Returns decimal value of roman numaral

int value(char s)
{
    if(s=='I')
        return 1;
    if(s=='V')
        return 5;
    if(s=='X')
        return 10;
    if(s=='L')
        return 50;
    if(s=='C')
        return 100;
    if(s=='D')
        return 500;
    if(s=='M')
        return 1000;
    return -1;
}

int romanToDecimal(string &str) {
    // code here
    int res=0,i,n=str.length(),s;
    for(i=0;i<n;i++)
    {
        s = value(str[i]);
        if(i+1<n)
        {
            if(s>=value(str[i+1]))
            {
                res += s;
            }
            else
            {
                res += value(str[i+1]) - s;
                i++;
            }
        }
        else
        {
            res += s;
        }
        //cout<<i<<" "<<res<<"\n";
    }
    return res;
    
}