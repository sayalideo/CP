// Find the Union and Intersection of the two sorted arrays.
// this code contains intersection
// Learn map in cpp

/* special case : a = [4,4], b = [4,4] so you can't use a count var for checking array
a's map in second for loop, as 2nd 4 in array b will be counted again
*/

#include<bits/stdc++.h>
#include<set>
using namespace std;
int NumberofElementsInIntersection (int a[], int b[], int n, int m );

// Given two arrays A and B and their sizes N and M respectively 
int NumberofElementsInIntersection (int a[], int b[], int n, int m )
{
    // Your code goes here
    /* METHOD 1 (working)
    map<int, int> d,ans;
    int count = 0,i;
    for(i=0;i<n;i++)
    {
        if(d[a[i]]==0)
            d[a[i]] = 1;
    }
    for(i=0;i<m;i++)
    {
        if(d[b[i]]==1)
            ans[b[i]] = 1
    }
    return ans.size(); 
    
    **************************
    
    METHOD 2*/
    set <int> s1{std::begin(a),std::end(a)};
    set <int> s2{std::begin(b),std::end(b)};
    set<int> intersect;
    set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),std::inserter(intersect, intersect.begin()));
    return intersect.size()
}

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int a[n], b[m];
		for(int i=0; i<n; i++)
			cin>>a[i];

		for(int i=0; i<m; i++)
			cin>>b[i];
			
		cout << NumberofElementsInIntersection(a,b,n,m) << endl;
	}
	return 0;
}  
//1.36
