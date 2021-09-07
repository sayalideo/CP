// { Driver Code Starts


#include <bits/stdc++.h>
#include<set>
using namespace std;

int main() {
    set <int> s;
    int a[] = {1,2,3,4}, b[]={3,4,5,6};
    set_intersection(a,a+4,b,b+4,std::inserter(s,s.begin()));
    // here, if a, b are sets or vectors, then use a.begin(), a.end()...
    for(auto i:s)
    {
        cout<<i<<" "; //op : 3 4
    }
    a[2] = 6;
    set_intersection(a,a+4,b,b+4,std::inserter(s,s.begin()));
    for(auto i:s)
    {
        cout<<i<<" ";   //op : 3 4 6
    }
	return 0;
}  // } Driver Code Ends