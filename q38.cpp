#include<bits/stdc++.h>
using namespace std;
// solved on my own
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),i,j;
        int low=0,high=m-1, x=target,row=-1,mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(x>=matrix[mid][0] && x<=matrix[mid][n-1])
            {
                row = mid;
                break;
            }
            else if(x>matrix[mid][n-1])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        if(row==-1)
            return false;
        low = 0;high=n-1;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(x==matrix[row][mid])
                return true;
            else if(x>matrix[row][mid])
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
}
};