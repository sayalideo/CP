// https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
#include<bits/stdc++.h>
using namespace std;

vector<char> findDuplicatesMap(string s)
{
    unordered_map <char, int> m;
    vector<char> v;
    int n = s.length(),i;
    for(i=0;i<n;i++)
    {
        m[s[i]] += 1;
        //cout<<"m "<<s[i]<<" "<<m[s[i]]<<"\n";
    }
    for(auto i:m)
    {
        if(i.second>1)
            v.push_back(i.first);
    }
    return v;
}



int main()
{
    int i;
    vector<char> v;
    string s;
    cin>>s;
    v = findDuplicatesMap(s);
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

}