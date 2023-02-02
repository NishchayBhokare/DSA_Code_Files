//Find permutations of string.
//GFG
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//TC - O(4^n * N),  SC-  O(N).
void solve(string str, vector<string> &ans, int index)
{
    if (index == str.length())
    {
    //for(int i=0; i<ans.size(); i++) if(str == ans[i]) return; //before pushing into ans vector, we can check whether current string is present in ans vector or not. so that duplicate strings will not present in ans vector.
        ans.push_back(str); //pushing current string into ans vector, when index reaches to the length of current str
        return;//returning.
    }

    for (int i = index; i < str.length(); i++) //looping from index value to the i less than string str length, to iterate over given string.
    {
        swap(str[i], str[index]); //First swap ith with index.
        solve(str, ans, index + 1); //call solve function for next index value

        // Backtrack position.
        swap(str[i], str[index]); //to restore previous position of current string, we need to backtrack, so this is situation of backtrack, where we are swapping ith value with index value to restore previous position.
    }
}

vector<string> find_permutation(string str)
{
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    sort(ans.begin(), ans.end()); //sorting ans to get answer in lexiograhical order
    ans.erase(unique(ans.begin(), ans.end()), ans.end()); //to remove duplicate strings from string vector.
    return ans;
}