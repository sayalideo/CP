// Minimise the maximum difference between heights [V.IMP]
// Adobe, Greedy Approach O(n) for actual, O(nlogn) for sorting => Overall nlogn
/* Given an array arr[] denoting heights of N towers and a positive integer K, 
you have to modify the height of each tower either by increasing or decreasing them by K only once. 
After modifying, height should be a non-negative integer. 
Find out what could be the possible minimum difference of the height of 
shortest and longest towers after you have modified each tower. */

#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        int ans,big,small,adder,subber,i;
        sort(arr,arr+n);
        ans = arr[n-1] - arr[0];
        // small = arr[0] + k;
        // big = arr[n-1] - k;

        // // Corner case when small is actually bigger than big after +/- k
        // if(small > big)
        // {
        //     swap(small,big);
        // }

        for(i=1;i<n;i++)
        {
            if(arr[i]-k>=0)
            {
                ans = min(ans,max(arr[n-1]-k,arr[i-1]+k)-min(arr[0]+k,arr[i]-k));
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
} 
// https://stackoverflow.com/questions/32233916/minimum-difference-between-heights-of-towers/63220955#63220955

/* It seems that the intuition behind the approach is that first you sort the array

now for the sorted array you calculate first

ans = arr[n-1] - arr[0]

// for the case that both of these elements be the same

// then you can add or subtract the same no to get

// the same original difference

and secondly

big = arr[n-1] - k

small = arr[0] + k

and big - small // i.e. ans - 2k

// now one of these would be the smallest

// and the proposition to get the min of the maximum difference

// after modifying the array holds

now for each element

Case A)

1): if it is < k then you can only add k to it since you need it to be non negative

2): the element is definitely >= a[0]+k

3): the element can only increase the max difference and also only if it turns out to be greater than big

Thus you find big = max(big,b[i]+k)

Case B)

1): if it is > k then you may either subtract or add such that the max difference increases the least

Thus here we use greedy */

// 0.42