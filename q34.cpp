// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;
int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}// } Driver Code Ends

int PalinArray(int a[], int n)
{  //add code here.
    int i, num, p, temp,sum;
    for(i=0;i<n;i++)
    {
        num = a[i];
        sum = 0;
        p = 0;
        //cout<<num<<"\n";
        while(num)
        {
            sum = sum*10 +  num%10;
            //cout<<num<<" "<<sum<<"\n";
            num = num/10;
            p++;
        }
        //cout<<sum<<"\n";
        if(sum != a[i])
            return 0;
    }
    return 1;
}