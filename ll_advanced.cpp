#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int element;
    Node *next;
};

void pushElement(Node **head,int ele)
{
    Node *n = new Node(),*temp;
    n->element = ele;
    n->next = NULL;
    if(*head == NULL)
        *head = n;
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

// This is a two-pointer approach requiring single traversal of linked list
// Here, move curr upto pos and until that, ref points to first node.
// Once curr reaches pos, move curr and ref together until curr reaches the end of the ll
// Print ref
// https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
int elementFromEnd(Node *head, int pos)
{
    Node *curr=head,*ref=head;
    int x=0;
    if(head==NULL)
        return 0;
    while(x!=pos && curr!=NULL)
    {
        x++;
        curr = curr->next;
    }
    if(x!=pos)
        return 0;
    while(curr)
    {
        ref = ref->next;
        curr = curr->next;
    }
    cout<<"Element : "<<ref->element<<"\n";
    return 1;
}

void printMiddle(Node *head)
{
    Node *temp=head,*mid=head;
    if(head==NULL)
        return;
    cout<<head->element<<"\n";
    while(temp!=NULL && temp->next!=NULL && temp->next->next!=NULL)
    {
        temp = temp->next->next;
        mid = mid->next;
    }
    cout<<"Middle element is : "<<mid->element<<"\n";
}

void display(Node *head)
{
    while (head)
    {
        cout<<head->element<<" ";
        head = head->next;
    }
    cout<<"\n";
    
}

void swapElements(Node **head)
{
    Node *temp=NULL, *prev=NULL, *tempa=NULL, *preva, *tempb=NULL, *prevb;
    int a,b;
    cout<<"Enter elements : ";
    cin>>a>>b;
    temp = *head;
    while(temp!=NULL)
    {
        if(temp->element==a)
        {
            preva = prev;
            tempa = temp;
        }
        if(temp->element==b)
        {
            prevb = prev;
            tempb = temp;
        }
        prev = temp;
        temp = temp->next;
        if(tempa != NULL && tempb != NULL)
            break;
    }
    if(preva != NULL)
        preva->next = tempb;
    else
        *head = tempb;
    if(prevb != NULL)
        prevb->next = tempa;
    else
        *head = tempa;    
    temp = tempa->next;
    tempa->next = tempb->next;
    tempb->next = temp;
}

void moveLast(Node **head)
{
    Node *prev = *head, *temp;
    if(prev == NULL || prev->next==NULL)    // 0 or 1 elements
        return;
    temp = prev->next;
    while(temp->next!=NULL)
    {
        prev =  temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->next = *head;
    *head = temp;
}

int main()
{
    Node *head=NULL;
    int flag = 1,x,ele;

    while(flag)
    {
        cout<<"\n1.Push Element\n2.Display\n3.Print nth element from the end\n4.Print Middle Element\n5.Swap two elements\n6.Move Last element to the front\n7.Exit\nEnter Choice : ";
        cin>>x;
        switch (x)
        {
        case 1:
                cout<<"Enter Element : ";
                cin>>ele;
                pushElement(&head,ele);
            break;
        case 2 : 
                display(head);
            break;
        case 4:
                printMiddle(head);
            break;
        case 5:
                cout<<"Before : ";
                display(head);
                swapElements(&head);
                cout<<"After : ";
                display(head);
            break;
        case 6: 
                cout<<"Before : ";
                display(head);
                moveLast(&head);
                cout<<"After : ";
                display(head);
            break;
        case 7:
                cout<<"Arigato Gozaimasu ^_^\n";
                flag = 0;
            break;
        case 3:
                cout<<"Enter position from the end : ";
                cin>>ele;
                ele = elementFromEnd(head,ele);
                if(!ele)
                    cout<<"Invalid position\n";
            break;
        default:
                cout<<"Wrong Input -_-\n";
            break;
        }
    }
}