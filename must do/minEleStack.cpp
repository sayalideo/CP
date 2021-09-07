// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/ 
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){

       int qt;
       cin>>qt;

       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }

}


// } Driver Code Ends


/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
    if(s.size()==0)
        return -1;
    return minEle;
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(s.size()==0)
        return -1;
   int x = s.top(),ans;
   s.pop();
   if(x<minEle)
   {
       ans = minEle;
       minEle = 2*minEle - x;
   }
   else
        ans = x;
    return ans;
}

/*push element x into the stack*/
void _stack::push(int x)
{
    if(s.empty())
        minEle = x;
   if(x>=minEle)
        s.push(x);
    else
    {
        s.push(2*x-minEle);
        minEle = x;
    }
}
