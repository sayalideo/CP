// Given an array of size n and a number k, find all elements that appear more than n/k times

#include<bits/stdc++.h>
#include<map>
using namespace std;

void countArray(int arr[], int n, int k)
{
    map <int, int> m;
    int i;
    printf("in\n");
    for(i=0;i<n;i++)
    {
        m[arr[i]] += 1;
    }
    for(auto i:m)
    {
        if(i.second>n/k)
        {
            cout<<i.first<<"\n";
        }

    }
}

int main()
{
    int t,i,j,n,k,arr[50];
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;
        for(j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        cin>>k;

        countArray(arr,n,k);
    }
}

// Hashing takes extra space. 
// Other techniques : https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/