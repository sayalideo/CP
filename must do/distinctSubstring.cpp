// https://practice.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1# 
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDitinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDitinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDitinctChars (string S)
{
    // your code here
    int n=S.length(),l,r,count=0;
    int table[26] = {0};
    table[S[0]-'a'] = 1;
    l=0;
    r=1;
    while(r<n)
    {
        cout<<S[l]<<" "<<S[r]<<" ";
        if(table[S[r]-'a']==0)
        {
            table[S[r]-'a']=1;
            count = max(count,r-l+1);
            r++;
        }
        else
        {
            while(S[l]!=S[r])
            {
                table[S[l]-'a'] = 0;
                l++;
            }
            table[S[l]-'a'] = 0;    
            l++;
        }
        cout<<count<<"\n";
    }
    return count;
}