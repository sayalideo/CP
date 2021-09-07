#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int ele;
    Node *next;
    Node(int x)
    {
        ele = x;
        next = NULL;
    }
};

    void push(Node **top, int ele)
    {
        Node *n = new Node(ele);
        if(*top==NULL)
        {
            *top = n;
        }
        else
        {
            n->next = *top;
            *top = n;
        }
    }
    void pop(Node **top)
    {
        Node *tos = *top;
        if(*top == NULL)
        {
            cout<<"Stack empty\n";
            return;
        }
        if(tos->next == NULL)
        {
            *top = NULL;
        }
        else
        {
            *top = tos->next;
        }
    }
    int peek(Node *top)
    {
        if(top==NULL)
        {
            cout<<"Stack empty\n";
            return INT_MIN;
        }
        return top->ele;
    }

int main()
{
    int i=1,x,ele;
    Node *top=NULL;
    while(i)
    {
        cout<<"1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter operation : ";
        cin>>x;
        switch(x)
        {
            case 1:
                    cout<<"Enter element : ";
                    cin>>ele;
                    push(&top,ele);
                    break;
            case 2:
                    pop(&top);
                    break;
            case 3:
                    ele = peek(top);
                    if(ele!=INT_MIN)
                        cout<<"Element at top : "<<ele<<"\n";
                    break;
            case 4:
                    i = 0;
                    cout<<"Adios\n";
                    break;
            default:
                    cout<<"Wrong option -_-\n";
                    break;
        }
    }
}