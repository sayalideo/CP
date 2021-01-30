// Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void sort012(int[],int);

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

// } Driver Code Ends


void sort012(int a[], int n)
{
    int zero=0,one=0,two=0,i;
    // coode here 
    for(i=0;i<n;i++)
    {
        if(a[i]==0){
            zero++;
        }
        else if(a[i]==1){
            one++;
        }
        else{
            two++;
        }
    }
    for(i=0;i<n;i++)
    {
        if(zero){
            a[i]=0;
            zero--;
        }
        else if(one){
            a[i]=1;
            one--;
        }
        else{
            a[i]=2;
            two--;
        }
    }
}