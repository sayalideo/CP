// Reverse the array
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int arr[100],n,i,j,temp,t;
    //cout << "Enter length of array : ";
    cin >> t;
    for(j=0;j<t;j++)
    {
        cin >> n;
    //cout << "Enter elements : ";
        for(i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        for(i=0;i<n/2;i++)
        {
            temp = arr[i];
            arr[i] = arr[n-i-1];
            arr[n-i-1] = temp;
        }
        //cout << "Reversed array : ";
        for(i=0;i<n;i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}