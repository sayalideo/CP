// Triplet Sum in Array 
// Using two-pointer technique : used to find two elements in an array that sum to a given value in O(N) time
#include <bits/stdc++.h>
using namespace std;


#include<map>
class Solution{
    public:
    
    bool find3Numbers(int arr[], int n, int X)
    {
        //Your Code Here
        int i,j,m,k,s;
        sort(arr,arr+n);
        for(i=0;i<n-2;i++)
        {
            m = X - arr[i];
            j = i+1;
            k = n-1;
            while(j<k)
            {
                s = arr[j]+arr[k];
                if(s == m)
                    return 1;
                else if(m>s)
                {
                    j++;
                }
                else{
                    k--;
                }
                
            }
        }
        return 0;
    }

};

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,sum;
		cin>>N>>sum;
		int i,A[N];
		for(i=0;i<N;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, N, sum) << endl;
    }
}

// Other method : hashing
// https://www.geeksforgeeks.org/find-a-triplet-that-sum-to-a-given-value/ 