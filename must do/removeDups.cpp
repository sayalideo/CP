// https://practice.geeksforgeeks.org/problems/remove-duplicates3034/1# 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
		
	string removeDups(string S) 
	{
	    int i,n=S.length();
	    int h[26] = {0};
	    string ans="";
	    for(i=0;i<n;i++)
	    {
	        if(h[S[i]-'a']==0)
	        {
	            ans += S[i];
	            h[S[i]-'a'] = 1;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   		
   		Solution ob;
   		cout << ob.removeDups(s) << "\n";
   		
   	}

    return 0;
}  // } Driver Code Ends