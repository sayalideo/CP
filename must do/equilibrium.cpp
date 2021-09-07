// https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1# 
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        int left = 0, right=n-1, suml = 0, sumr = 0;
        while(left<=right)
        {
            
            if(suml+a[left] == sumr+a[right])
            {
                suml += a[left];
                sumr += a[right];
                left++;
                right--;
            }
            else if(suml+a[left]<sumr+a[right])
            {
                suml += a[left];
                left++;
            }
            else
            {
                sumr += a[right];
                right--;
            }
            cout<<"left : "<<a[left]<<", Right : "<<a[right]<<", suml : "<<suml<<", sumr : "<<sumr<<"\n";
        }
        if(right+2 == left && sumr==suml)
            return left;
        else
            return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends