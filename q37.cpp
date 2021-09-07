//  solved on my own
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
public:     
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int i=0,j=0,rc=0,cc=0,d=0,steps=0;
        vector<int> ans;
        while(cc!=c && rc!=r)
        {
            
            ans.push_back(matrix[i][j]);
            //cout<<matrix[i][j]<<" ";
            if(d==0)
            {
                steps++;
                if(steps==c-cc)
                {
                    rc++;
                    steps=0;
                    d++;
                    i++;
                }
                else
                j++;
 
            }
            else if(d==1)
            {
                steps++;
                if(steps==r-rc)
                {
                    cc++;
                    steps=0;
                    d++;
                    j--;
                }
                else
                {
                    i++;
                }
            }
            else if(d==2)
            {
                steps++;
                if(steps==c-cc)
                {
                    rc++;
                    steps=0;
                    d++;
                    i--;
                }
                else
                    j--;
            }
            else
            {
                steps++;
                if(steps==r-rc)
                {
                    cc++;
                    steps=0;
                    d=0;
                    j++;
                }
                else
                {
                    i--;
                    
                }
            }
        }
        return ans;
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];               
            }
        }
        // cout<<matrix[r-1][c-1]<<"\n";
        
        // for(int i=0;i<r;i++)
        // {
        //     for(int j=0;j<c;j++)
        //     {
        //         cout<<i<<j<<" ";
        //         cout<<matrix[i][j]<<"\n";
        //     }
        // }
        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends