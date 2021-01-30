// Move all the negative elements to one side of the array i.e. to the left side
// Neat-o
// Learnt queue STL
// Code runs in O(n)
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


void segregateElements(int [], int );

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}
#include <queue>
void segregateElements(int arr[],int s)
{
    // Your code goes here
    int p=0,temp,j,n=-1,count=0;
    queue <int> q;
    for(p=0;p<s;p++)
    {
        if(arr[p]<0)
        {
            q.push(arr[p]);           
        }
        else
        {
            n++;
            arr[n] = arr[p];
        }        
    }
    while(!q.empty())
    {
        arr[++n] = q.front();
        q.pop();
    }
}

// 0.4