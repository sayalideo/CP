// Subarray with 0 sum | Easy | PayTM
// Given an array of positive and negative numbers. 
// Find if there is a subarray (of size at-least one) with 0 sum.

#include <bits/stdc++.h>
using namespace std;


bool subArrayExists(int arr[], int n);
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    	if (subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}// } Driver Code Ends


// O(n^2) solution
// bool subArrayExists(int arr[], int n)
// {
//     int i,j,sum;
//     for(i=0;i<n;i++)
//     {
//         sum = 0;
//         for(j=i;j<n;j++)
//         {
//             sum = sum + arr[j];
//             if(sum == 0)
//             return true;
//         }        
//     }
//     return false;
// }

// ************************************************************
// O(n) solution
/* arr[] = {1, 4, -2, -2, 5, -4, 3}

If we consider all prefix sums, we can
notice that there is a subarray with 0
sum when :
1) Either a prefix sum repeats or
2) Or prefix sum becomes 0.

Prefix sums for above array are:
1, 5, 3, 1, 6, 2, 5

Since prefix sum 1 repeats, we have a subarray
with 0 sum. */
#include<map>

bool subArrayExists(int arr[], int n)
{
        map <int, bool> m ;
        int sum=0,i;
        for(i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum == 0 || m[sum]==true )
                return true;
            else
            {
                m[sum] = true;
            }
            
        }
        return false;
}

// 1.77