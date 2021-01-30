// Given an array, rotate the array by one position in clock-wise direction.
/* Input : N = 5
A[] = {1, 2, 3, 4, 5}
Output:5 1 2 3 4 */
#include <stdio.h>

void rotate(int arr[], int n);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
        return 0;
}
// } Driver Code Ends


void rotate(int a[], int n)
{
    int i,last = a[n-1];
    for(i=n-1;i>=1;i--)
    {
        a[i] = a[i-1];
    }
    a[0] = last;
}
//0.01