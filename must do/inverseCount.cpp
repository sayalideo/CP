// here i tried it without sending temp[] everywhere between calls.
// I just create a temp arr in merge.
// the only diff is in line 38. Here as i is starting from 0, mid-i+1 is no longer an option.
// we have to subtract low as well to balance.
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int merge(long long int arr[], long long int low, long long int mid, long long int high)
    {
         long long int left[mid-low+1], right[high-mid],temp=0,i,j,k;
         for(i=low;i<=mid;i++)
         {
             left[i-low] = arr[i];
         }
         for(j=mid+1;j<=high;j++)
         {
             right[j-mid-1] = arr[j];
         }
         i=0;
         j=0;
         k = low;
         while(i<(mid-low+1) && j<(high-mid))
         {
             if(left[i]<=right[j])
             {
                 arr[k] = left[i];
                 i++;
             }
             else
             {
                 temp += mid-i-low+1;
                 arr[k] = right[j];
                 j++;
             }
             k++;
         }
         while(i<(mid-low+1))
         {
             arr[k] = left[i];
             k++;
             i++;
         }
         while(j<(high-mid))
         {
             arr[k] = right[j];
             k++;
             j++;
         }
         cout<<"low : "<<low<<",  mid : "<<mid<<",  high : "<<high<<",  temp : "<<temp<<"\n";
         return temp;
         
    }
    
    long long int mergeSort(long long int arr[], long long int low, long long int high)
    {
        long long int mid,count=0;
        if(low<high)
        {
            mid = (high+low)/2;
            count += mergeSort(arr,low,mid);
            count += mergeSort(arr,mid+1,high);
            count += merge(arr,low,mid,high);
        }
        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        long long int count = mergeSort(arr,0,N-1);
        return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends    