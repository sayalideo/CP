// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends

struct node
{
    int element;
    int i;
    int j;
};

class Heap
{
    public:
        int heap_size;
        node *harr;
        int left_child(int i) { return 2*i+1;}
        int right_child(int i) {return 2*i+2;}
        node get_min() { return harr[0]; }
        void replace_min(node new_node)
        {
            harr[0] = new_node;
            minHeapify(0);
        }
        void swap(int small, int i)
        {
            node temp = harr[small];
            harr[small] = harr[i];
            harr[i] = temp;
        }
        Heap(node arr[],int size)
        {
            harr = arr;
            heap_size = size;
            int i = (heap_size-1)/2;
            while(i>=0)
            {
                minHeapify(i);
                i--;
            }
        }
        
        void minHeapify(int i)
        {
            int left = left_child(i), right = right_child(i), smallest = i;
            if(left < heap_size && harr[left].element < harr[smallest].element)
                smallest = left;
            if(right < heap_size && harr[right].element < harr[smallest].element)
                smallest = right;
            if(smallest != i)
            {
                swap(smallest,i);
                minHeapify(smallest);
            }
        }
};


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    node arr[n],new_node,temp;
    int i,j;
    for(i=0;i<n;i++)
    {
        arr[i].element = mat[i][0];
        arr[i].i = i;
        arr[i].j = 1;
    }
    Heap hp(arr,n);
    for(int count=0;count<k-1;count++)
    {
        temp = hp.get_min();
        if(temp.j<hp.heap_size)
        {
            new_node.element = mat[temp.i][temp.j];
        }
        else
        {
            new_node.element = INT_MAX;
        }
            new_node.i = temp.i;
            new_node.j = temp.j + 1;
            hp.replace_min(new_node);

    }
    new_node = hp.get_min();
    return new_node.element;
}
