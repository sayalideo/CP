// Smallest subarray with sum greater than x | could not solve all test cases 
// Given an array of integers (A[])  and a number x, find the smallest subarray with 
// sum greater than the given value.

// Note: The answer always exists. It is guaranteed that x doesn't exceed 
// the summation of a[i] (from 1 to N).

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
// ************* my failed solution ******************
    // int sb(int arr[], int n, int x)
    // {
    //     int lower=0,upper=0,sum = 0,count=0,result=INT_MAX;
    //     while(lower<n || upper<n)
    //     {
    //         if(upper >= n)
    //         {
    //             cout<<"here1\n";
    //             while(lower<n && sum-arr[lower]>x)
    //             {
    //                 sum -= arr[lower];
    //                 lower++;
    //                 count--;
    //                 cout<<lower<<upper<<sum<<count<<"\n";
    //             }
    //             result = min(result,count);
    //             break;
    //         }
    //         else if(sum+arr[upper]<=x)
    //         {
    //             cout<<"here2\n";
    //             sum += arr[upper];
    //             upper++;
    //             count++;
    //         }
    //         else if(sum+arr[upper]>x)
    //         {
    //             cout<<"here3\n";
    //             if(sum<=x)
    //             {
    //                 sum += arr[upper];
    //                 upper++;
    //                 count++;
    //             }

    //             if(sum-arr[lower]>x)
    //             {
    //                 sum = sum - arr[lower];
    //                 lower++;
    //                 count--;
    //             }
    //             else
    //             {
    //                 lower++;
    //                 upper = lower;
    //                 if (count!=0 && sum>x)
    //                     result = min(result,count);
    //                 count = 0;
    //                 sum = 0;
    //             }
                
                
    //         }
    //         cout<<lower<<" "<<upper<<" "<<sum<<" "<<count<<"\n";
    //     }
    //     if (count!=0 && sum>x)
    //         result = min(result,count);
    //     return result;
    // }



// ********************* gfg solution *********************
int sb(int arr[], int n, int x)
{
    // Initialize current sum and minimum length
    int curr_sum = 0, min_len = n + 1;
 
    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n) {
        // Keep adding array elements while current sum
        // is smaller than or equal to x
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];
 
        // If current sum becomes greater than x.
        while (curr_sum > x && start < n) {
            // Update minimum length if needed
            if (end - start < min_len)
                min_len = end - start;
 
            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}
};

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.sb(a,n,x)<<endl;
	}
	return 0;
} 