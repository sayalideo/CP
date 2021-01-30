/* Find the maximum and minimum element in an array */
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int a[100],min=9999,max=-9999,i,n;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter elements : ";
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]<min)
            min = a[i];
        if(a[i]>max)
            max = a[i];
    }
    printf("Max : %d\tMin : %d",max,min);
}