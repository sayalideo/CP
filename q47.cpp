class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size(),i;
        char temp;
        for(i=0;i<n/2;i++)
        {
            temp = s[i];
            s[i] = s[n-i-1];
            s[n-1-i] = temp;
        }
    }
};