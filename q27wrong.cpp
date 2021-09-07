// Find whether an array is a subset of another array
// !!!!!!!!!!!!!! ATTENTION !!!!!!!!!!!!!!!!!!!
// I misunderstood this problem for subarray problem
// This is a subset problem! Not a sub array problem!
// Below is the wrong solution
#include <iostream>
# define SIZE 100000
using namespace std;

void isSubset(int arr[], int sub[] ,int m, int n)
{
    int i=0,j,first=0,flag=0;
    while(i<m)
    {
        if(arr[i]==sub[0])
        {
            flag = 0;
            for(j=1;j<n;j++)
            {
                //cout<<"a,s ",arr[i+j],sub[j],"\n";
                if(arr[i+j]==sub[0])
                    first = j;
                if(i+j>m)
                {
                    cout<<"No"<<"\n";
                    return;
                }
                if(arr[i+j]!=sub[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0)
            {
                cout<<"Yes"<<"\n";
                return;
            }
        }
        if(first>i)
            i = first;
        else
            i++;
    }
    cout<<"No"<<"\n";
}

int main() {
	//code
	
	int t, arr[SIZE], sub[SIZE], i,j, m, n;
	cin>>t;
	for(i=0;i<t;i++)
	{
	    cin>>m>>n;
	    for(j=0;j<m;j++)
	    {
	        cin>>arr[j];
	    }
	    for(j=0;j<n;j++)
	    {
	        cin>>sub[j];
	    }
	    isSubset(arr,sub,m,n);
	}
	return 0;
}