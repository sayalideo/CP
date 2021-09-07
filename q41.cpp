#include<bits/stdc++.h>
using namespace std;
#define N 4

struct minHeapNode{
    int element;
    int i;
    int j;
};

class MinHeap
{
    public:
        minHeapNode *harr;
        int heap_size;
        int left_child(int i) { return 2*i + 1;}
        int right_child(int i) { return 2*i + 2;}
        minHeapNode get_min() 
        { 
            //cout<<harr[0].element<<"\n";
            return harr[0]; 
        }
        void replace_min(minHeapNode ele)
        {
            harr[0] = ele;
            minHeapify(0);
        }
    MinHeap(int arr[], int size)
    {
        minHeapNode *narr = new minHeapNode[N];
        for(int i=0;i<size;i++)
        {
            narr[i].element = arr[i];
            narr[i].i = i;
            narr[i].j = 1;
            //cout<<narr[i].element<<" "<<narr[i].i<<" "<<narr[i].j<<"\n";
        }
        harr = narr;
        heap_size = size;
        int i=(heap_size-1)/2;
        while(i>=0)
        {
            minHeapify(i);
            i--;
        }
    }

    void swap(minHeapNode *i, minHeapNode *smallest)
    {
        minHeapNode temp = *i;
        *i = *smallest;
        *smallest = temp;
    }
    void minHeapify(int i)
    {
        // printf("%d \nHeap : ",i);
        // for(int j = 0;j<N;j++)
        //     printf("%d ",harr[j].element);
        // printf("\n");
        int smallest = i, left = left_child(i), right = right_child(i);
        if(left<heap_size && harr[left].element < harr[i].element)
            smallest = left;
        if(right<heap_size && harr[right].element < harr[smallest].element)
            smallest = right;
        if(smallest != i)
        {
            swap(&harr[i],&harr[smallest]);
            minHeapify(smallest);
        }
    }
};

void printSorted(int mat[][N])
{
    int arr[N],i;
    minHeapNode ele;
    for(i=0;i<N;i++)
    {
        arr[i] = mat[i][0];
    }
    MinHeap mh(arr,N);
    int count = N*N;
    for(i = 0;i < count; i++)
    {
        //cout<<i<<" : Count\n";
        ele = mh.get_min();
        cout<<ele.element<<" ";
        if(ele.j<N)
        {
            ele.element = mat[ele.i][ele.j];
            ele.j = ele.j + 1;
        }
        else
        {
            ele.element = INT_MAX;
        }      
        mh.replace_min(ele);
    }

}
int main()
{
  int mat[N][N] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printSorted(mat);
  return 0;
}