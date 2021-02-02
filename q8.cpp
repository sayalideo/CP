// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
// Kadane's Algorithm | 21 company tags | arrays, DP
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    // Your code here
    int curr_max = arr[0], max_so_far = arr[0],i;
    for(i=1;i<n;i++)
    {
        curr_max = max(arr[i], curr_max+arr[i]); // so that if we hav negative val in curr_max, we dont take it
        max_so_far = max(curr_max, max_so_far);
    }
    return max_so_far;
}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
/*  Subarray indices start and end in this code

int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0, 
       start =0, end = 0, s=0; 
  
    for (int i=0; i< size; i++ ) 
    { 
        max_ending_here += a[i]; 
  
        if (max_so_far < max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
  
        if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    } 
    cout << "Maximum contiguous sum is "
        << max_so_far << endl; 
    cout << "Starting index "<< start 
        << endl << "Ending index "<< end << endl; 
} */

//0.28