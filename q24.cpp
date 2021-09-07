// CONGRATULATIONS ! THIS IS YOUR FIRST MEDIUM LEVEL PROB THAT WORKS ON YOUR OWN (by just using hint : hashing) W/O REFERRING TO SOLUTION. KEEP IT UP!
// Longest consecutive subsequence | 3 companies | medium level | hashing
// Given an array of positive integers. 
// Find the length of the longest sub-sequence such that elements in the subsequence 
// are consecutive integers, the consecutive numbers can be in any order.

// Other Approaches : https://www.geeksforgeeks.org/longest-consecutive-subsequence/

#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}

#include<map>
int findLongestConseqSubseq(int arr[], int N)
{
  //Your code here
  map <int,int> m;
  int i,big=arr[0],small=arr[0],mid,range=0,flag=0;
  for(i=0;i<N;i++)
  {
    m[arr[i]] += 1;
    if(arr[i]>big)
        big = arr[i];
    if(arr[i]<small)
        small = arr[i];
  }
  i=small+1;
  while(i<=big)
  {
      //printf("\n*********************\nsmall = %d, big = %d, i = %d\nrange = %d\n",small,big,i,range);
      if(m[i]==0)
      {
          flag = 1;
          mid = floor((small+big)/2);
          if(i>=mid) 
          {
              
              range=max(range,i-small);
              break;
          }
          else
          {
              range=max(range,i-small);
              small = i+1;
          }
            
      }
      else
      {range = max(range,i-small+1);}
      i++;
  }
    if(flag==0)
    range = big-small+1;
  return range;
}
// 1.25

