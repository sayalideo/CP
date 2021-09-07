// https://practice.geeksforgeeks.org/problems/implement-atoi/1# 
 #include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
        /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int ans=0,d,flag=0;
        for(int i=0;i<str.length();i++)
        {
            if(i==0 && str[0]=='-')
            {
                flag = 1;
            }
            else
            {
                d = str[i]-48;
            //cout<<d;
                if(d<0 || d>9)
                    return -1;
                ans =  ans*10 + d;
            //cout<<ans<<"\n";
            }
        }
        if(!flag)
            return ans;
        return -1*ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends