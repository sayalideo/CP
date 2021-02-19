// Learn to convert array to set, set to vector
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#include <set>
class Solution
{

    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            set <int> a,b,c,t,ans;
            a = makeSet(A,n1);
            b = makeSet(B,n2);
            c = makeSet(C,n3);
            set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::inserter(t,t.begin()));
            set_intersection(c.begin(), c.end(), t.begin(), t.end(), std::inserter(ans,ans.begin()));
            vector <int> v(ans.begin(), ans.end());
            return v;
        }

    public:
        set <int> makeSet (int A[], int n)
        {
            set <int> s;
            for(int i=0; i<n; i++)
            {
                s.insert(A[i]);
            }
            return s;
        }
};

// { Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends