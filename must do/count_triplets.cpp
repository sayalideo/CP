// https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    int i,j,triplets=0,start,stop;
	    sort(arr,arr+n);
	    for(i=0;i<n;i++)
	    {
	        start = 0;
	        stop = n-1;
	        while(start<stop)
	        {
	            if(arr[start] + arr[stop] == arr[i] && start!=i && stop !=i)
	            {
	                triplets++;
	            }
	            if(arr[start] + arr[stop]>arr[i])
	                stop--;
	            else
	                start++;
	        }
	    }
	    return triplets;
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends