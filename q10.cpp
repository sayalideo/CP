// Minimum number of jumps
/* Given an array of integers where each element represents the max number 
of steps that can be made forward from that element. Find the minimum number of jumps 
to reach the end of the array (starting from the first element). 
If an element is 0, then you cannot move through that element. */

// Adobe Amazon Housing.com Moonfrog Labs Walmart | DP | very tough
// N=11  arr=1 3 5 8 9 2 6 7 6 8 9  Output: 3 


#include<bits/stdc++.h>
using namespace std;

// works for test case and then gives time out
// int minJumps(int arr[], int n){
//     int i = 0,steps = 0,mi,mx,j,s;
//     while(i<n)
//     {
//         mi = i;
//         mx = i+arr[i];
//         s = 0;
//         for(j=mi;j<mx;j++)
//         {
//             s = max(s,arr[j]);
//         }
//         i = i + s;
//         steps++;
//     }
//     return steps;
// }


// In this method, we build jumps[] array from right to left such that jumps[i] indicates 
// the minimum number of jumps needed to reach arr[n-1] from arr[i]. Finally, we return arr[0]. 
// works in n^2
// int minJumps(int arr[], int n){
//     int* jumps = new int[n];
//     int min;
 
//     // Minimum number of jumps needed
//     // to reach last element from last
//     // elements itself is always 0
//     jumps[n - 1] = 0;
 
//     // Start from the second last element,
//     // move from right to left and
//     // construct the jumps[] array where
//     // jumps[i] represents minimum number
//     // of jumps needed to reach
//     // arr[n-1] from arr[i]
//     for (int i = n - 2; i >= 0; i--) {
//         // If arr[i] is 0 then arr[n-1]
//         // can't be reached from here
//         if (arr[i] == 0)
//             jumps[i] = INT_MAX;
 
//         // If we can direcly reach to
//         // the end point from here then
//         // jumps[i] is 1
//         else if (arr[i] >= n - 1 - i)
//             jumps[i] = 1;
 
//         // Otherwise, to find out the minimum
//         // number of jumps needed to reach
//         // arr[n-1], check all the points
//         // reachable from here and jumps[]
//         // value for those points
//         else {
//             // initialize min value
//             min = INT_MAX;
 
//             // following loop checks with all
//             // reachable points and takes
//             // the minimum
//             for (int j = i + 1; j < n && j <= arr[i] + i; j++) {
//                 if (min > jumps[j])
//                     min = jumps[j];
//             }
 
//             // Handle overflow
//             if (min != INT_MAX)
//                 jumps[i] = min + 1;
//             else
//                 jumps[i] = min; // or INT_MAX
//         }
//     }
 
//     return jumps[0];
// }


  
// Works in O(n)
// The most efficient DP solution
int minJumps(int arr[], int n) 
{ 
  
    // The number of jumps needed to 
    // reach the starting index is 0 
    if (n <= 1) 
        return 0; 
  
    // Return -1 if not possible to jump 
    if (arr[0] == 0) 
        return -1; 
  
    // initialization 
    // stores all time the maximal 
    // reachable index in the array. 
    int maxReach = arr[0]; 
  
    // stores the number of steps 
    // we can still take 
    int step = arr[0]; 
  
    // stores the number of jumps 
    // necessary to reach that maximal 
    // reachable position. 
    int jump = 1; 
  
    // Start traversing array 
    int i = 1; 
    for (i = 1; i < n; i++) { 
        // Check if we have reached the end of the array 
        if (i == n - 1) 
            return jump; 
  
        // updating maxReach 
        maxReach = max(maxReach, i + arr[i]); 
  
        // we use a step to get to the current index 
        step--; 
  
        // If no further steps left 
        if (step == 0) { 
            // we must have used a jump 
            jump++; 
  
            // Check if the current index/position or lesser index 
            // is the maximum reach point from the previous indexes 
            if (i >= maxReach) 
                return -1; 
  
            // re-initialize the steps to the amount 
            // of steps to reach maxReach from position i. 
            step = maxReach - i; 
        } 
    } 
  
    return -1; 
} 
  

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends