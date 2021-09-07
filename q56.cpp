#include<bits/stdc++.h>
using namespace std;

string printSubsequence(string input, string output)
{
    if(input == "")
        return "";
    printSubsequence(input.substr(1),output+input[0]);
    printSubsequence(input.substr(1),output);
}

int main()
{
    // output is set to null before passing in as a
    // parameter
    string output = "";
    string input = "abcd";
 
    printSubsequence(input, output);
 
    return 0;
}