// Idiot cant even solve such a simple code. Looked in the solution

#include <bits/stdc++.h>
#include<map>
using namespace std;

#define M 4
#define N 5

void printCommonElements(int mat[][N])
{
    map <int, int> m;
    for(int i=0;i<N;i++)
    {
        m[mat[0][i]] = 1;
    }
    for(int i=1;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(m[mat[i][j]] == i)
            {
                m[mat[i][j]] = i+1;
            }
                
            
        }
    }
    for(auto i:m)
    {
        if(i.second==M)
            cout<<i.first<<" ";
    }
}

int main()
{
    int mat[M][N] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    printCommonElements(mat);
 
    return 0;
}