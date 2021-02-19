// Long Factorial 1 <= n <= 1000

#include <iostream>
#define MAX 10000
using namespace std;

void factorial(int n)
{
    int res[MAX],carry,res_size=1,j,pro;
    res[0] = 1;
    
    for(int i=2;i<=n;i++)
    {
        carry = 0;
        for(j=0;j<res_size;j++)
        {
            pro = res[j]*i + carry;
            res[j] = pro%10;
            carry  = pro/10;

        }
        while(carry)
        {
            res[res_size] = carry%10;
            carry /= 10;
            res_size++; 
        }
    }
    for(int i=res_size-1;i>=0;i--)
    {
        cout<<res[i];
    }
}

int main() {
	int t,n;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        factorial(n);
        cout<<"\n";
    }
	return 0;
}
//0.38