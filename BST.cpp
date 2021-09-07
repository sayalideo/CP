#include<bits/stdc++.h>
using namespace std;

class BST
{
    public:
    int data;
    BST *left;
    BST *right;

    BST()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    BST(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }

    BST * insert(BST* root, int x)
    {
        if(root==NULL)
        {
            root = new BST(x);
            return root;
        }
        if(x>root->data)
        {
            root->right = insert(root->right,x);
        }
        else
        {
            root->left = insert(root->left,x);
        }
        return root;
    }

    void inorder(BST* root)
    {
        if(root)
        {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
};

int main()
{
    BST *b,*root=NULL;
    root = b->insert(root,3);   // first time it does not make changes in *root present in main, but its copy (call by value)/ Thus, assignment required
    b->insert(root,5);          // from next time onwards, its fine
    b->insert(root,2);
    b->insert(root,4);
    b->insert(root,1);
    b->inorder(root);
    return 0;
}