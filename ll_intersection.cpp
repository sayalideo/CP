#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
};

void pushElement(Node **head, int ele)
{
    Node *n = new Node();
    Node * temp;
    n->data = ele;
    n->next = NULL;
    if(*head == NULL)
    {
        *head = n;
    }
    else
    {
        temp = *head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void display(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

void intersection(Node **h1, Node **h2, Node **h3)
{
    Node *temp1=*h1, *temp2=*h2, *temp3=*h3, *prev=NULL, *n;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data == temp2->data)
        {
            n = new Node();
            n->data = temp1->data;
            n->next = NULL;
            if(prev == NULL)
            {
                *h3 = n;
                prev = n;
            }
            else
            {
                prev->next = n;
                prev = n;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {
            if(temp1->data<temp2->data)
                temp1 = temp1->next;
            else
                temp2 = temp2->next;
        }
    }
}

int main()
{
    Node *h1=NULL, *h2=NULL, *h3=NULL;
    int e;
    cout<<"Enter list 1 elements : ";
    for(int i=0;i<5;i++)
    {
        cout<<"Enter element : ";
        cin>>e;
        pushElement(&h1,e);
    }
    cout<<"Enter list 2 elements : ";
    for(int i=0;i<4;i++)
    {
        cout<<"Enter element : ";
        cin>>e;
        pushElement(&h2,e);
    }
    display(h1);
    display(h2);
    intersection(&h1, &h2, &h3);
    display(h3);
}