// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/ 

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class MinHeap{
  public:
    int *harr;
    int hsize;
    MinHeap(int arr[], int n)
    {
        int i;
        harr = arr;
        hsize = n;
        i = (n-1)/2;
        while(i>=0)
        {
            minHeapify(i);
            i--;
        }
    }
    void minHeapify(int i)
    {
        int left,right,smallest=i;
        left = 2*i+1;
        right = 2*i+2;
        if(left<hsize && harr[left]<harr[smallest])
            smallest = left;
        if(right<hsize && harr[right]<harr[smallest])
            smallest = right;
        if(smallest != i)
        {
            swap(harr[smallest],harr[i]);
            minHeapify(smallest);
        }
    }
    
    void extractMin()
    {
        harr[0] = harr[hsize-1];
        hsize--;
        minHeapify(0);
    }
    
    int getMin()
    {
        return harr[0];
    }
};


class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        int i=0,temp;
        MinHeap mh(arr,r-l+1);
        while(i<k-1)
        {
            mh.extractMin();
            i++;
        }
        return mh.getMin();
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends