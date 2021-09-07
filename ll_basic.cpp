// Inserting elements in the linked list
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int element;
        Node *next;
};

void insertBeg(Node **head, int ele)
{
    Node *n;
    n = new Node();
    n->element = ele;
    n->next = NULL;
    if(*head != NULL)
    {
        n->next = *head;
    }
    *head = n;
    return;
    
}

void insertEnd(Node **head,int ele)
{
    Node *n,*temp;
    n = new Node();
    n->element = ele;
    n->next = NULL;
    if(*head==NULL)
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
    return;
    
}

bool insertAfter(Node **head,int ele,int src)
{
    Node *temp,*n;
    n = new Node();
    n->element = ele;
    n->next = NULL;
    if(*head==NULL)
    {
        return 0;
    }
    temp = *head;
    while(temp!=NULL && temp->element != src)
    {
        temp = temp->next;
    }
    if(temp==NULL)
        return 0;
    if(temp->next==NULL)
    {
        temp->next = n;
    }
    else
    {
        n->next = temp->next;
        temp->next = n;
    }
    return 1;
}

bool insertBefore(Node **head,int ele,int src)
{
    Node *temp,*prev = NULL,*n;
    n = new Node();
    n->element = ele;
    n->next = NULL;
    if(*head == NULL)
        return 0;
    temp = *head;
    if(temp->element==src)
    {
        n->next = *head;
        *head = n;
        return 1;
    }

    while(temp!=NULL && temp->element!=src)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp==NULL)
        return 0;
    
    prev->next = n;
    n->next = temp;
    return 1;
}

bool deleteNode(Node **head, int ele)
{
    Node *prev=NULL,*temp=*head;
    if(*head==NULL)
        return 0;
    while(temp!=NULL)
    {
        if(temp->element==ele)
        {
            if(prev==NULL)
            {
                *head = temp->next;
                delete temp;
                return 1;
            }
            prev->next = temp->next;
            delete temp;
            return 1;
        }
        prev = temp;
        temp = temp->next;
    }
    return 0;
}

void deleteList(Node **head)
{
    if(*head==NULL)
        return;
    Node *temp,*curr = *head;
    while(curr!=NULL)
    {
        temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int countNodes(Node *head)
{
    int count=0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

void display(Node *head)
{
    while(head)
    {
        cout<<head->element<<" ";
        head = head->next;
    }
    cout<<"\n";
    return;
}

int main()
{
    Node *head = NULL;
    int x,ele,flag=0,src;
    bool b;
    while(!flag)
    {
        cout<<"1.Enter Beginning\n2.Enter End\n3.Enter After\n4.Enter Before\n5.Delete Node\n6.Delete Linked List\n7.Count Nodes\n8.Display\n9.Exit\nEnter Choice :  ";
        cin>>x;
        switch (x)
        {
        case 1:
                cout<<"Enter the element : ";
                cin>>ele;
                insertBeg(&head,ele);
                break;
        case 2:
                cout<<"Enter the element : ";
                cin>>ele;
                insertEnd(&head,ele);
                break;
        case 3:
                cout<<"Enter the element to be entered : ";
                cin>>ele;
                cout<<"Enter the target element : ";
                cin>>src;
                b = insertAfter(&head,ele,src);
                if(!b)
                    cout<<"Element "<<src<<" does not exist\n";
                break;
        case 4:
                cout<<"Enter the element to be entered : ";
                cin>>ele;
                cout<<"Enter the target element : ";
                cin>>src;
                b = insertBefore(&head,ele,src);
                if(!b)
                    cout<<"Element "<<src<<" does not exist\n";
                break;
        case 5:
                cout<<"Enter the element to be deleted : ";
                cin>>ele;
                b = deleteNode(&head,ele);
                if(!b)
                    cout<<"Element "<<ele<<" does not exist\n";
                break;
        case 6:
                deleteList(&head);
                break;
        case 7:
                ele = countNodes(head);
                cout<<"Total number of nodes = "<<ele<<"\n";
                break;
        case 8:
                display(head);
                break;
        case 9:
                cout<<"Arigato Gozaimasu ^_^\n";
                flag=1;
                break;
        default:
                cout<<"Wrong Chice -_-!\n";
                break;
        }
    }
    
    return 0;
}