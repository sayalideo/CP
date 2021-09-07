// https://practice.geeksforgeeks.org/problems/last-index-of-15847/1 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
    public:
    int lastIndex(string s) 
    {
        int n=s.length(),i,last=-1;
        for(i=0;i<n;i++)
        {
            if(s[i]=='1')
                last = i;
        }
        return last;
    }

};

// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.lastIndex(s) << endl;
    }
    return 0;
}  // } Driver Code Ends