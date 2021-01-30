// Find the Union and Intersection of the two sorted arrays.
// this code contains union
// Learn map in cpp

#include <bits/stdc++.h>
using namespace std;

int doUnion(int *, int , int *, int);

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	   
	    cout << doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}// } Driver Code Ends


//User function template in C++

// a and b : given array with n and m size respectively

int doUnion(int a[], int n, int b[], int m)  {
    //code here
    map<int, int> d;
    int i,j,ans[n+m];
    for(i=0;i<n;i++)
    {
        d[a[i]] = d[a[i]] + 1;
    }
    for(i=0;i<m;i++)
    {
        d[b[i]] = d[b[i]] + 1;
    }
    j = 0;
    /*for(auto item : d)
    {
        ans[j] = item.first;
        j++;
    } */
    return d.size();
}

//1.85