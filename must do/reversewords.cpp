// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1 
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans="";
        int i=S.length()-1,j,k;
        while(i>=0)
        {
            j = i;
            while(j>=0 && S[j]!='.')
                j--;
            k = j;
            j++;
            while(j<=i)
            {
                ans += S[j];
                j++;
            }
            if(k>0)
                ans += '.';
            i = k-1;
        }
        return ans;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends