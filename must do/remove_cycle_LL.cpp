// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1# - 
// https://www.geeksforgeeks.org/detect-and-remove-loop-in-a-linked-list/ 
// Working code from comment section
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


 // } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to remove a loop in the linked list.
    // void removeCycle(Node *head, Node *loop)
    // {
    //     Node *ptr1 = head, *ptr2=loop;
    //     if(ptr1==ptr2)
    //     {
    //         while(ptr2->next != ptr1)
    //         {
    //             ptr2 = ptr2->next;
    //         }
    //         ptr2->next=NULL;
    //         return;
    //     }
    //     while(ptr1!=loop)
    //     {
    //         ptr2 = loop;
    //         while(ptr2->next != loop && ptr2->next!=ptr1)
    //             ptr2 = ptr2->next;
    //         if(ptr2->next==ptr1)
    //         {
    //             ptr2->next = NULL;
    //             break;
    //         }
    //         ptr1 = ptr1->next;
    //     }
    // }
    
    void removeLoop(Node* head)
    {
    Node *slow=head;
    Node *fast = head;
    if(head == NULL || head->next == NULL)
        return;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            break;
        }
    }
    if(slow==head){
        while(slow->next!=head){
            slow=slow->next;
        }
        slow->next = NULL;
    }
    if(slow == fast){
        slow = head;
        while(slow->next != fast->next){
            if(slow == fast->next){
                fast->next == NULL;
            }
            slow = slow->next;
            fast = fast->next;
        }

        fast->next=NULL;
    }
// code here
// just remove the loop without losing any nodes
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}
  // } Driver Code Ends