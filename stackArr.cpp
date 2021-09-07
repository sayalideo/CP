#include<bits/stdc++.h>
using namespace std;
#define MAX 3 
class Stack
{
    public:
    int arr[MAX];
    int top;
    Stack()
    {
        top = -1;
    }
    bool push(int data)
    {
        if(top>=MAX-1)
        {
            cout<<"Stack overflow\n";
            return 0;
        }
        arr[++top] = data;
        return 1;
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack empty\n";
            return;
        }
        top--;
    }
    int peek()
    {
        if(top==-1)
        {
            cout<<"Stack empty\n";
            return INT_MIN;
        }
        return arr[top];
    }
};

int main()
{
    Stack s;
    int i=1,ele,x;
    while(i)
    {
        cout<<"1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter operation : ";
        cin>>x;
        switch(x)
        {
            case 1:
                    cout<<"Enter element : ";
                    cin>>ele;
                    s.push(ele);
                    break;
            case 2:
                    s.pop();
                    break;
            case 3:
                    ele = s.peek();
                    if(ele!=INT_MIN)
                        cout<<"Element at Top : "<<ele<<"\n";
                    break;
            case 4:
                    i = 0;
                    cout<<"Sayonara\n";
                    break;
            default:
                    cout<<"Wrong option -_-\n";
                    break;
        }
    }
}