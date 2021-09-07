// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Stack
{
    public:
    vector <long long int> arr;
    int tos;
    Stack()
    {
        tos = -1;
    }
    void push(long long int data)
    {
        arr.push_back(data);
        tos++;
    }
    void pop()
    {
        arr.pop_back();
        tos--;
    }
    long long int peek()
    {
        if(tos==-1)
            return -1;
        return arr[tos];
    }
};

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        unordered_map <long long int, long long int> mp;
        Stack s;
        s.push(arr[0]);
        long long int x;
        vector<long long int> ans;
        for(int i=1;i<n;i++)
        {
            x = s.peek();
            while(x!=-1 && x<arr[i])
            {
                mp[s.peek()] = arr[i];
                s.pop();
                x = s.peek();
            }
            s.push(arr[i]);
        }
        x = s.peek();
        while(x!=-1)
        {
                mp[s.peek()] = -1;
                s.pop();
                x = s.peek();
        }
        for(int i=0;i<n;i++)
        {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};




// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1# 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends