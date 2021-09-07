// Trapping Rain Water | vvv imp | 5 methods in gfg
// https://www.geeksforgeeks.org/trapping-rain-water/
// Given an array arr[] of N non-negative integers representing the height of blocks. 
// If width of each block is 1, compute how much water can be trapped between the blocks 
// during the rainy season. 

#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends


class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        // Code here
        int i,high,low,left_max=INT_MIN,right_max = INT_MIN,result=0;
        high = n-1;
        low = 0;
        while(low<=high)
        {
            if(arr[low]<arr[high])
            {
                if(left_max<arr[low])
                {
                    left_max = arr[low];
                }
                else
                {
                    result += left_max - arr[low];
                }
                low++;
            }
            else
            {
                if(right_max<arr[high])
                {
                    right_max = arr[high];
                }
                else
                {
                    result += right_max - arr[high];
                }
                high --;         
            }
            
        }
        return result;
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