// https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/
// Minimum swaps required to bring all elements less than or equal to k together
// Given an array of n positive integers and a number k. Find the minimum number of swaps required to bring all the numbers less than or equal to k together.
// medium | could not pass all cases in O(n)
#include <iostream>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends

// my solution just shifts everything to one side of the array
// does not pass all test cases where all the elements must be shifted to the middle just to reduce the number of swaps
// int minSwap(int *arr, int n, int k) {
//     // Complete the function
//     int i=-1,j,swap=0,temp,swapr=0,rswap=0;
//     int c[n];
    
//     for(j=0;j<n;j++)
//     {
//         c[j] = arr[j];
//         if(arr[j]<=k)
//         {
//             i++;
//             temp = arr[j];
//             arr[j] = arr[i];
//             arr[i] = temp;
//             if(i!=j)
//                 swap++;
//         }
//     }
//     i=n;
//     for(j=n-1;j>=0;j--)
//     {
//         arr[j] = c[j];
//         if(c[j]<=k)
//         {
//             i--;
//             temp = c[j];
//             c[j] = c[i];
//             c[i] = temp;
//             if(i!=j)
//                 swapr++;                        
//         }
//     }
//     i=n;
//     for(j=n-1;j>=0;j--)
//     {
//         c[j] = arr[j];
//         if(arr[j]>k)
//         {
//             i--;
//             temp = arr[j];
//             arr[j] = arr[i];
//             arr[i] = temp;
//             if(i!=j)
//                 rswap++;                        
//         }
//     }
//     cout<<swapr<<swap<<rswap<<"\n";
//     return min(min(swapr,swap),rswap);
// }

int minSwap(int *arr, int n, int k) { 
      
    // Find count of elements which are 
    // less than equals to k 
    int count = 0; 
    for (int i = 0; i < n; ++i) 
        if (arr[i] <= k) 
            ++count; 
      
    // Find unwanted elements in current 
    // window of size 'count' 
    int bad = 0; 
    for (int i = 0; i < count; ++i) 
        if (arr[i] > k) 
            ++bad; 
      
    // Initialize answer with 'bad' value of 
    // current window 
    int ans = bad; 
    for (int i = 0, j = count; j < n; ++i, ++j) { 
          
        // Decrement count of previous window 
        if (arr[i] > k) 
            --bad; 
          
        // Increment count of current window 
        if (arr[j] > k) 
            ++bad; 
          
        // Update ans if count of 'bad' 
        // is less in current window 
        ans = min(ans, bad); 
    } 
    return ans; 
} 
