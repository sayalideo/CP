// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1# 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
    

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
        int i,mx=INT_MIN,temp;
        vector<int> sol;
        for(i=n-1;i>=0;i--)
        {
            if(a[i]>=mx)
            {
                sol.push_back(a[i]);
                mx = a[i];
            }
        }
        mx = sol.size(); 
        for(i=0;i<mx/2;i++)
        {
            temp = sol[i];
            sol[i] = sol[mx-i-1];
            sol[mx-i-1] = temp;
        }
        return sol;
    }
};

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends