// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1 
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

#define max 32000

class Stack
{
    public:
    char arr[max];
    int tos;
    Stack()
    {
        tos = -1;
    }
    void push(char ele)
    {
        if(tos<max-1)
        {
            arr[++tos] = ele;
        }
    }
    char pop()
    {
        if(tos<0)
            return '0';
        return arr[tos--];
    }
};

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    
    bool ispar(string x)
    {
        Stack s;
        int i=0,n=x.length();
        char ele;
        for(i=0;i<n;i++)
        {
            if(x[i] == '(' || x[i]=='[' || x[i]=='{')
            {
                s.push(x[i]);
            }
            else
            {
                ele = s.pop();
                if((ele=='[' && x[i]==']') || (ele=='(' && x[i]==')') || (ele=='{' && x[i]=='}'))
                    continue;
                return 0;
            }
        }
        if(s.tos==-1)
            return 1;
        return 0;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends