// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

string longestPalin (string S);
int main()
{

        string S; cin >> S;

        cout << longestPalin (S) << endl;

}

string printStr(int a, int b, string S)
{
    string ans;
    int i;
    for(i=a;i<=b;i++)
    {
        ans.push_back(S[i]);
    }
    return ans;
}


string longestPalin (string S)
{
    int n = S.length(),i,j,k,count = 1,a,b;
    int dp[n][n];
    for(i=0;i<n;i++)
    {
        
        for(k = 0,j=i;j<n;j++,k++)
        {
            // dp[k][i+j] dp[j][i+j] = 
            if(S[k]==S[j])
            {
                if(j==k || j==k+1 || dp[k+1][j-1] == 1)
                {
                    dp[k][j] = 1;
                    if(j-k+1>count)
                    {
                        count = j-k+1;
                        a = k;
                        b = j;
                        
                    }
                    
                }
                else
                {
                    dp[k][j] = 0;
                }
                
            }
            else
            {
                dp[k][j] = 0;
            }
            
          //  cout<<"count : "<<count<<" k : "<<k<<"; j : "<<j<<" dp : "<<dp[k][j]<<"\n";
        }
    }
    return printStr(a,b,S);
}