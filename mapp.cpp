#include<iostream>
#include<map>
#include<stdio.h>
using namespace std;
int main()
{
    map<int,int> m;
    m[1] = 0;
    m[2] = 0;
    m[1] = m[1] + 1;
    for ( auto item : m )
    {
        //item.first is the key
        cout << item.first << " goes ";

        //item.second is the value
        cout << item.second << endl;
    }
    printf("%d",m[3]);
    return 0;
}