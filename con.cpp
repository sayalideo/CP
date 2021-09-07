#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.length(),i,count=1,mx = 1;
        unordered_map <char, int> m;
        
        for(i=1;i<n;i++)
        {
            if(word[i]>=word[i-1])
            {
                count++;
                //cout<<count<<" "<<i<<"\n";
            }
            else
            {
                count = 1;
            }
            mx = max(mx,count);
        }
        return mx;
    }
};
int main()
{
    Solution s;
    cout<<s.longestBeautifulSubstring("aeiaaioaaaaeiiiiouuuooaauuaeiu");
}