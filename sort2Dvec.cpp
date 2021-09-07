#include<bits/stdc++.h>
#include<vector> // for 2D vector
#include<algorithm> // for sort()
using namespace std;
bool col(const vector <int>& v1, const vector <int>& v2)
{
    return v1[0] < v2[0];
}
int main()
{
    int i,j;
    vector< vector<int> > vect{{3, 5, 1},
                                {7, 2, 9},
                                {4, 8, 6},
                                };
    sort(vect.begin(),vect.end(),col);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<vect[i][j]<<" ";
        }
    }
}

/*
Another way is 

for(int i = 0; i < arr.size(); i++) {
            intervals.push_back(make_pair(arr[i][0], arr[i][1]));
        }
        sort(intervals.begin(), intervals.end());

*/