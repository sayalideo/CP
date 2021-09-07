// Array Subset of another array
// This code passes one test case in vscode but does not pass that case in gfg
// https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/
// very interesting solutions mentioned in gfg
# include<bits/stdc++.h>
#include<map>
using namespace std;

int main()
{
    int t,i,j,m,n,a,flag = 0;
    map<int, int> arr, sub;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>m>>n;
        for(j=0;j<m;j++)
        {
            cin>>a;
            arr[a] += 1;
        }
        for(j=0;j<n;j++)
        {
            cin>>a;
            sub[a] += 1;
        }
        for(auto i:arr)
        {
            cout<<i.first<<i.second<<"\n";
        }
        for(auto i:sub)
        {
            cout<<i.first<<i.second<<"\n";
        }
        for(auto i:sub)
        {
            cout<<i.first<<i.second<<arr[i.first]<<"\n";
            if(i.second != arr[i.first])
            {
                flag = 1;
                printf("No\n");
                break;
            }
        }
        if(flag==0)
            printf("Yes\n");
        arr.clear();
        sub.clear();
    }
}