// Find the row with maximum number of 1s

// Mind blowing solution. Did not think of it.
// Solved on my own after knowing the logic

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    int i,j,index=m,mx=-1;
	    for(i=m-1;i>-1;i--)
	    {
	        if(arr[0][i]==1)
	         {
	             index = i;
	             mx = 0;
	         }
	         else
	            break;
	    }
	    for(i=1;i<n;i++)
	    {
	        for(j=index-1;j>-1;j--)
	        {
	            if(arr[i][j] == 1)
	            {
	                index = j;
	                mx = i;
	            }
	            else
	                break;
	        }
	    }
	    return mx;
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends