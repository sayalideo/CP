// Find the "Kth" max and min element of an array 
// It is given that all array elements are distinct.
// Method 2 uses heaps and is less than nlogn. 2 more methods on gfg
// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
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
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends

//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function

void merge(int arr[], int l, int p, int r)
{
    int la[p-l+1], ra[r-p],i,j,k;
    for(i=0;i<p-l+1;i++)
    {
        la[i] = arr[l+i];
    }
    for(j=0;j<r-p;j++)
    {
        ra[j] = arr[p+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<p-l+1 && j<r-p)
    {
        if(la[i]<ra[j])
        {
            arr[k] = la[i];
            i++;
        }
        else
        {
            arr[k] = ra[j];
            j++;
        }
        k++;        
    }
    while(i<p-l+1)
    {
        arr[k] = la[i];
        k++;
        i++;
    }
    while(j<r-p)
    {
        arr[k] = ra[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    int p;
    if(l<r)
    {
        p = (l+r)/2;
        mergeSort(arr,l,p);
        mergeSort(arr,p+1,r);
        merge(arr,l,p,r);
    }
}

int kthSmallest(int arr[], int l, int r, int k) 
{
    //code here
    int i;
    mergeSort(arr,l,r);
    return arr[k-1];
}