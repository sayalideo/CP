#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string prev = countAndSay(n-1),ans,temp;
        int i,l=prev.length(),count,j;
        char c;
        
        for(i=0;i<l;)
        {
            count = 1;
            j = i+1;
            while(j<l && prev[i]==prev[j])
            {
                j++;
                count++;
            }
            if(count<=9)
            {
                c= count+48;
                ans.push_back(c);
                //cout<<"* "<<c<<" ";
            }
            else
            {
                c = count%10+48;
                ans.push_back(c);
                c = count/10 + 48;
                ans.push_back(c);
            }
            
            //ans.push_back(to_string(count));
            c = prev[i];
            ans.push_back(c);
            //cout<<"* "<<c<<" ";
            //cout<<"* "<<ans<<"\n";
            i = j;
        }
        //cout<<n<<" "<<ans<<"\n";
        return ans;
    }
};

int main()
{
    Solution s;
    cout<<s.countAndSay(5);
}