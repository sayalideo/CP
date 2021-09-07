// https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places-1587115620/1 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.length() != str2.length())
            return 0;
        if(str1.length() < 2)
            return str1.compare(str2) == 0;
        string clockw="",antic="";
        int len = str1.length();
        clockw = clockw + str1.substr(2,len-2) + str1.substr(0,2);
        antic = antic + str1.substr(len-2,2) + str1.substr(0,len-2);
        return (str2.compare(clockw) == 0) || (str2.compare(antic) == 0);
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends