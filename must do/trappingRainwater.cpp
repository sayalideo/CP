// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int low=0,high=n-1,lowl=0,highl=n-1,count=0;
        while(low<=high)
        {
            if(arr[low]<arr[high])
            {
                if(arr[low]>=arr[lowl])
                {
                    lowl = low;
                }
                else
                {
                    count += arr[lowl]-arr[low];
                }
                low++;
            }
            else
            {
                if(arr[high]>=arr[highl])
                {
                    highl = high;
                }
                else
                {
                    count += arr[highl] - arr[high];
                }
                high--;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends