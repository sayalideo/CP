// https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1 
// https://www.geeksforgeeks.org/longest-common-prefix-using-sorting/ correct ans
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        if(N==1)
            return arr[0];
        int ans = 0,j;
        string prefix=arr[0],temp;
        for(int i=1;i<N;i++)
        {
            j = 0;
            temp = "";
            while(j<prefix.length() && j<arr[i].length() && prefix[j]==arr[i][j])
            {
                
                temp += prefix[j];
                j++;
            }
            prefix = "";
            for(int k=0;k<j;k++)
            {
                prefix += temp[k];
            }
            
        }
        if(prefix.length() > 0)
            return prefix;
        return "-1";
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends