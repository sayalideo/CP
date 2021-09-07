// Element with left side smaller and right side greater 

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int findElement(int arr[], int n) {
    if(n==1 || n==2)
        return -1;  // end condition
    int min_arr[n],i,min_left=arr[0],element=-1;
    min_arr[0] = arr[0];
    for(i=1;i<n-1;i++)
    {
        min_arr[i] = min_left;
        if(arr[i]>min_left)
            min_left = arr[i];
        
    }
    
    min_left = arr[n-1];
    
    for(i=n-2;i>0;i--)
    {
        if(arr[i]<=min_left)
        {
            min_left = arr[i];
        
            if(arr[i]>=min_arr[i])
            {
                element = arr[i];
            }
        }
    }
    return element;
}