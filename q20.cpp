/* Rearrange array in alternating positive & negative items with O(1) extra space | Set 1 | Hard
The idea is to process array from left to right. While processing, 
find the first out of place element in the remaining unprocessed array. 
An element is out of place if it is negative and at odd index, or it is positive and at even index. 
Once we find an out of place element, we find the first element after it with opposite sign. 
We right rotate the subarray between these two elements (including these two).

This solution takes O(n^2) time but retains order of the elements in O(n) space

#include<bits/stdc++.h>
using namespace std;
 
void rightShift(int a[], int i, int k)
{
    int temp = a[k];
    for(int j=k;j>i;j--)
    {
        a[j] = a[j-1];
    }
    a[i] = temp;
}

int main()
{
    int n,a[100],i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        if((a[i]<0 && i%2==0) || (a[i]>=0 && i%2==1))
        {
            for(j=i+1;j<n;j++)
            {
                if((a[i]>=0 && a[j]<0) || (a[i]<0 && a[j]>=0))
                {  
                    rightShift(a,i,j);
                    break;
                }
                
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
} */

// ********************************************************************

/* If we are allowed to change order of appearance, we can solve this problem in O(n) time and O(1) space.
The idea is to process the array and shift all negative values to the end in O(n) time. 
After all negative values are shifted to the end, we can easily rearrange array in alternating 
positive & negative items. We basically swap next positive element at even position from next 
negative element in this step. */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a[100],i,j,pos=0,neg,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    neg = n-1;
    while(pos<neg) // moving all positives to the left and negatives to the right
    {
        if(a[pos]<0 && a[neg]>=0)
        {
            temp = a[pos];
            a[pos] = a[neg];
            a[neg] = temp;
            pos++;
            neg--;
        }
        if(a[pos]>=0)
            pos++;
        if(a[neg]<0)
            neg--;       
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    // now place them alternatively
    j = neg+1; // no of positive elements
    pos = 1;
    if(a[neg]>0 || neg%2==1) neg++;

    // neg = neg+1;
    // if (neg%2==1)
    //     neg += 1;
    // temp = neg;
    printf("%d neg\n",neg);
    if(j>n-j)
    {
        while(pos<n && neg<n)
        {
            temp = a[pos];
            a[pos] = a[neg];
            a[neg] = temp;
            pos += 2;
            neg += 1;
        }
    }
    else if(j<=n-j)
    {printf("ok\n");
        while(pos<n && neg<n)
        {
            temp = a[pos];
            a[pos] = a[neg];
            a[neg] = temp;
            pos += 2;
            neg += 1;
        }
    }

    
    

    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}