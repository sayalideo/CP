// Merge 2 sorted arrays without using Extra space.
// Given two sorted arrays arr1[] and arr2[] of sizes N and M in non-decreasing order. 
// Merge them in sorted order without using any extra space. 
// Modify arr1 so that it contains the first N elements and modify arr2 
// so that it contains the last M elements.
#include <bits/stdc++.h> 
#include<iostream>

using namespace std; 

// This code works with O(m*n) 
// Worst case : ar1 has all elements greater than ar2
// void merge(int arr1[], int arr2[], int m, int n) 
// { 
//      int i,j,last;
//      for(i=n-1;i>=0;i--)
//      {
//          last = arr1[m-1];
//          for(j=m-2;j>=0 && arr1[j]>arr2[i];j--)
//          {
//              arr1[j+1] = arr1[j];
//          }
//          if(j!=m-2 || last > arr2[i])
//          {
//              arr1[j+1] = arr2[i];
//              arr2[i] = last;
//          }
//      }
// } 

// ***************************************************************************
// This code works O((n+m)*log(n+m))
// https://www.geeksforgeeks.org/efficiently-merging-two-sorted-arrays-with-o1-extra-space/

// Function to find next gap.
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}

void merge(int arr1[], int arr2[], int n, int m)
{
    int gap=m+n,i,j;

    for(gap = nextGap(gap);gap>0;gap=nextGap(gap))
    {
        // comparing elements in the first array
        for(i=0;i+gap<n;i++)
        {
            if(arr1[i]>arr1[i+gap])
                swap(arr1[i],arr1[i+gap]);
        }

        // comparing elements in both arrays
        for(j = gap>n ? gap-n : 0; i<n && j<m; i++,j++)
        {
            if(arr1[i]>arr2[j])
                swap(arr1[i],arr2[j]);
        }

        if(j<m)
        {
            // Comparing elements in the second array
            for(j=0;j+gap<m;j++)
            {
                if(arr2[j]>arr2[j+gap])
                    swap(arr2[j],arr2[j+gap]);
            }
        }
    }
}

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    int arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    
	    merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            printf("%d ", arr1[i]); 
        
       
	    for (int i = 0; i < m; i++) 
		    printf("%d ", arr2[i]); 
	    
	    cout<<endl;
	}

	return 0; 
} 
  // 0.32