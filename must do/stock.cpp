// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1# 
// All test cases passed in total 1 hour ;-P 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n){
        // code here
        vector <vector <int>> ans;
        vector <int> temp;
        int i,mi=0,mx=0,d=0;
        for(i=1;i<n;i++)
        {
            if(d==1 && A[i]<A[mx])
            {
                    if(temp.size() != 0)
                    {
                        temp.pop_back();
                        temp.pop_back();
                    }
                    temp.push_back(mi);     
                    temp.push_back(mx);
                    ans.push_back(temp);
                    d = 0;
                    mi = i;
                    mx = i;
            }
            if(A[i]<=A[mi])
            {

                mi = i;
                mx = i;
            }
            else
            {
                if(A[i]>A[mx])
                {
                    mx = i;
                    d = 1;
                    if(i==n-1)
                        d=2;
                }
            }
            //cout<<"i : "<<i<<"; A[i] : "<<A[i]<<"; mx : "<<mx<<"; mi : "<<mi<<"; d : "<<d<<"\n";    
        }
        if(d==2)
        {
                    if(temp.size() != 0)
                    {
                        temp.pop_back();
                        temp.pop_back();
                    }
                    temp.push_back(mi);     
                    temp.push_back(mx);
                    ans.push_back(temp);
        }
        return ans;
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);

        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
        }

    }
    return 0;
}

  // } Driver Code Ends