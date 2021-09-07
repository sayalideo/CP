// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void rearrange(long long *arr, int n) 
    {
    	long long temp,me = arr[0] + arr[n-1];
    	int maxi=n-1, mini=0,i;
    	for(i=0;i<n;i++)
    	{
    	    if(i%2==0)
    	    {
    	        arr[i] = arr[i] + (arr[maxi]%me)*me;
    	        maxi--;
    	    }
    	    else
    	    {
    	        arr[i] = arr[i] + (arr[mini]%me)*me;
    	        mini++;
    	    }
    	}
        for(i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
            arr[i] = arr[i]/me;
        }    	
        cout<<"\n";
    }
};

int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 
  // } Driver Code Ends