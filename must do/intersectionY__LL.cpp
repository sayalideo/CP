// https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/ 
// https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/ 
#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;
    
    int val;
    cin>> val;
    
    Node *head = new Node(val);
    Node *tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;
        
        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);
        
        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;
        
        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int count1=0,count2=0,d;
    Node *temp,*temp2;
    temp = head1;
    while(temp!=NULL)
    {
        temp = temp->next;
        count1++;
    }
    temp = head2;
    while(temp!=NULL)
    {
        temp = temp->next;
        count2++;
    }
    if(count1>count2)
    {
        d = count1-count2;
        temp = head1;
        temp2 = head2;
    }
    else
    {
        d = count2 - count1;
        temp = head2;
        temp2 = head1;
    }
    while(d!=0)
    {
        temp = temp->next;
        d--;
    }
    while(temp!=NULL && temp != temp2)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }
    if(temp==NULL)
        return -1;
    return temp->data;
    
}

