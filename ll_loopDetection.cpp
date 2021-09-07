#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int element;
    Node* next;
};

void insertBeg(Node **head, int ele)
{
    Node *n = new Node();
    n->element = ele;
    n->next = *head;
    *head = n;    
}

void addCycle(Node **head)
{
    Node *temp = *head;
    temp->next->next->next = temp->next; 
}

bool detectCycle(Node *head)
{
    unordered_set<Node *> s;
    while(head)
    {
        if(s.find(head)!=s.end())
        {
            return true;
        }
        s.insert(head);
        head = head->next;
    }
    return false;
}

void display(Node *head)
{
    while(head)
    {
        cout<<head->element<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main()
{
    Node *head = NULL;
    int x,ele,flag=1;
    while(flag)
    {
        cout<<"\n1.Enqueue Element\n2.Display\n3.Add cycle\n4.Detect Loop\n5.Exit\nEnter Choice : ";
        cin>>x;
        switch (x)
        {
        case 1:
            cout<<"Enter Element : ";
            cin>>ele;
            insertBeg(&head,ele);
            break;
        case 2:
            display(head);
            break;
        case 3:
            addCycle(&head);
            break;
        case 4:
            if(detectCycle(head))
            {
                cout<<"Cycle Detected\n";
            }
            else
            {
                cout<<"No Cycle\n";
            }
            
            break;
        case 5:
            flag = 0;
            break;
        default:
            break;
        }
    }

}