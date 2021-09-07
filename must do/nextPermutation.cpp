// https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1# 
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string str)
		{
		    sort(str.begin(), str.end());
        
            vector<string> res;
        
            do
            {
                res.push_back(str);
            }
            while(next_permutation(str.begin(), str.end()));
        
            return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends