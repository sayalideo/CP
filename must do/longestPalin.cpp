// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1 
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    string longestPalin (string S) {
        // code here
        int i,maxlength=1,n=S.length(),start=0,high,low;
        string ans="";
        for(i=1;i<n;i++)
        {
            // first considering even length palindromes
            low = i-1;
            high = i;
            while(low>=0 && high<n && S[low]==S[high])
            {
                if(maxlength < high-low+1)
                {
                    maxlength = high-low+1;
                    start = low;
                }
                low--;
                high++;
            }
            
            // Considering odd length palindromes
            low = i-1;
            high = i+1;
            while(low>=0 && high<n && S[low]==S[high])
            {
                if(maxlength < high-low+1)
                {
                    maxlength = high-low+1;
                    start = low;
                }
                low--;
                high++;
            }
        }
        if(maxlength==1)
            ans += S[0];
        else{
                for(i=start;i<start+maxlength;i++)
            {
                ans += S[i];
            }            
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
