// Median of 2 sorted arrays of equal size
// https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
// A Simple Merge based O(n) solution to find median of two sorted arrays
#include <bits/stdc++.h>
using namespace std;
 
/* This function returns 
median of ar1[] and ar2[].
Assumptions in this function:
Both ar1[] and ar2[] 
are sorted arrays
Both have n elements */
int getMedian(int ar1[], int ar2[], int n)
{
    int i=0,j=0,ans;
    while(i<n && j<n)
    {
        if(i+j+1 == n)
            break;
        if(ar1[i]<ar2[j])
            i++;
        else
        {
            j++;
        } 
       
    }
    cout<<i<<" "<<j<<"\n";
    if(i>j)
    {
        if(i==n-1)
        {
            ans = float(ar1[i] + ar2[j])/2;
        }
        else
        {
            ans = float(ar1[i] + ar1[i+1])/2;
        }
    }
    else if(j>i)
    {
        if(j == n-1)
        {
            ans = float(ar1[i] + ar2[j])/2;
        }
        else
        {
            ans = float(ar2[j] + ar2[j+1])/2;
        }
    }
    else
    {
        ans = float(ar1[i]+ar2[j])/2;
    }
    return ans;
    
}
 
// Driver Code
int main()
{
    int ar1[] = {1, 2, 3, 6};
    int ar2[] = {4, 6, 8, 10};
 
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is "
             << getMedian(ar1, ar2, n1) ;
    else
        cout << "Doesn't work for arrays"
             << " of unequal size" ;
    //getchar();
    return 0;
}
