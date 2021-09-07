// Chocolate Distribution Problem | Easy | Learnt Vectors
// Given an array A[ ] of positive integers of size N, where each value represents 
// the number of chocolates in a packet. Each packet can have a variable number of chocolates. 
// There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and 
// minimum number of chocolates given to a student is minimum.

// Ans : We first sort the array arr[0..n-1], then find the subarray of size m with the minimum difference between the last and first elements.

#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a,long long n, long long m);

int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		cout<<findMinDiff(a,n,m)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    vector <long long> diff;
    long long first,last,result=INT_MAX,temp;
    sort(a.begin(),a.end());

    first = 0;
    last = m-1;
    while(last<n)
    {
        temp = a[last] - a[first];
        if(temp<result)
            result = temp;
        last ++;
        first++;
    }
    return result;
}