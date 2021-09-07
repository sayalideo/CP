// https://practice.geeksforgeeks.org/problems/missing-number-in-array1416/1
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int MissingNumber(vector<int>& arr, int n) {
        // Your code goes here
        int total=1,i;
        for(i=0;i<n-1;i++)
        {
            total += i+2;
            total -= arr[i];
        }
        return total;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
} 