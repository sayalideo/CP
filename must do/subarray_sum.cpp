// https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        int curr_sum = 0,i,prev=0,j;
        vector<int> res;
        for(i=0;i<n;i++)
        {
            curr_sum += arr[i];
            if(curr_sum == s)
            {
                res.push_back(prev+1);
                res.push_back(i+1);
                break;
            }
            else if(curr_sum > s)
            {
                while(curr_sum>s)
                {
                    curr_sum -= arr[prev];
                    prev++;
                    
                }
                if(curr_sum == s)
                {
                res.push_back(prev+1);
                res.push_back(i+1);
                    break;                  
                }
            }
            
        }
        if(curr_sum!=s)
            res.push_back(-1);
        return res;
        
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends