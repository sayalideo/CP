// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void sort012(int arr[], int n)
{
   int zeros=0,ones=0,twos=0,i;
   for(i=0;i<n;i++)
   {
       if(arr[i]==0)
            zeros += 1;
       else if(arr[i]==1)
            ones += 1;
       else
            twos += 1;
   }
   for(i=0;i<n;i++)
   {
       if(zeros)
       {
           arr[i] = 0;
           zeros--;
       }
       else if(ones)
       {
           arr[i] = 1;
           ones--;
       }
       else
       {
           arr[i] = 2;
           twos--;
       }
   }
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends