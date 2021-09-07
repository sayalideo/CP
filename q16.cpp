// Count Inversions
// o(nlogn) | Adobe, Amazon, Flipkart, BankBaazar, Microsoft, Myntra

// Given an array of integers. Find the Inversion Count in the array. 

// Inversion Count: For an array, inversion count indicates how far (or close) the array 
// is from being sorted. If array is already sorted then the inversion count is 0. 
// If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// tricky part
// How to get the number of inversions in merge()? 
// In merge process, let i is used for indexing left sub-array and j for right sub-array. 
// At any step in merge(), if a[i] is greater than a[j], then there are (mid – i) inversions. 
// because left and right subarrays are sorted, so all the remaining elements in left-subarray 
// (a[i+1], a[i+2] … a[mid]) will be greater than a[j]

#include <bits/stdc++.h>
using namespace std;

long long int merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
    long long int i=left,j=mid,k=left,count = 0;

    while(i<=mid-1 && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            count = count + mid - i; // tricky part
        }
    }
    while(i<=mid-1)
    {
        temp[k++] = arr[i++];
    }
    while(j<=right)
    {
        temp[k++] = arr[j++];
    }
    for(i=left;i<=right;i++)
    {
        arr[i] = temp[i];
    }
    cout<<"low : "<<left<<",  mid : "<<mid<<",  high : "<<right<<",  temp : "<<count<<"\n";
    return count;
    
}

long long int mergeSort(long long arr[], long long temp[], long long left, long long right)
{
    long long int mid,inversion = 0;
    if(right>left)
    {
        mid = (left+right)/2;
        inversion += mergeSort(arr,temp,left,mid);
        inversion += mergeSort(arr,temp,mid+1,right);
        inversion += merge(arr,temp,left,mid+1,right);
    }
    return inversion;
}

long long int inversionCount(long long arr[], long long N)
{
   long long int temp[N];
   return  mergeSort(arr,temp,0,N-1);
}

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
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends