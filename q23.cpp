//Maximum Product Subarray | 5 companies | DP
//Given an array Arr that contains N integers (may be positive, negative or zero). 
//Find the product of the maximum product subarray.
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


//User function template for C++
class Solution{
public:

	// My solution -
    // Fails for test cases when multiple neg-ve numbers are present one after the other
	// long long maxProduct(int *arr, int n) {
	//     long long max_save=0, max_product=1;
    //     int prev_neg=0,i,curr_neg=0,two=0;
    //     for(i=0;i<n;i++)
    //     {
    //         if(arr[i]>0)
    //         {
    //             max_product *= arr[i]; 
    //         }
    //         else if(arr[i]<0)
    //         {
    //             if(two!=0)
    //             {
    //                 max_product = max_product*curr_neg*arr[i];
    //                 prev_neg = curr_neg;
    //                 curr_neg = arr[i];
    //                 prev_neg = 0;
    //             }
    //             else
    //             {
    //                 prev_neg = arr[i];
    //             }
                
    //         }
    //         else
    //         {
    //             max_product = 1;
    //             prev_neg = 0;
    //         }
    //         max_save = max(max_save,max_product);  
    //         printf("i=%d max_save=%lld, maxPro = %lld, prev_neg=%d\n",arr[i],max_save,max_product,prev_neg);     
            
    //     }
    //     return max_save;
	// }
    long long maxProduct(int *arr, int n) {
        long long int max_so_far = 0, max_ending_here = 1, min_ending_here = 1, temp;
        int i,flag = 0;
        for(i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                max_ending_here = max_ending_here*arr[i];
                if(min_ending_here*arr[i]<1)
                    min_ending_here *= arr[i];
                else
                    min_ending_here = 1;
                flag = 1;
            }
            else if(arr[i]==0)
            {
                max_ending_here = 1;
                min_ending_here = 1;
            }
            else
            {
                temp = max_ending_here;
                if(min_ending_here*arr[i] > 1)
                    max_ending_here = min_ending_here*arr[i];
                else
                    max_ending_here = 1;
                min_ending_here = temp*arr[i];
            }
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
        }
        if (flag == 0 && max_so_far == 0)
            return 0;
        return max_so_far;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends