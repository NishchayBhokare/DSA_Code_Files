// Example to find letter combination of phone number
// GFG
    // Input: N = 3, a[] = {2, 3, 4}
    // Output:
    // adg adh adi aeg aeh aei afg afh afi 
    // bdg bdh bdi beg beh bei bfg bfh bfi 
    // cdg cdh cdi ceg ceh cei cfg cfh cfi 
    // Explanation: When we press 2,3,4 then 
    // adg, adh, adi, ... cfi are the list of 
    // possible words.

#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;


//TC - O(4^n * N),  SC-  O(N).
void solve(int a[], int n, string temp, vector<string> mapping, vector<string> &ans, int index)
{
    if (index == n)
    {
        ans.push_back(temp); //when condition reach to length of array a. then push temp in ans vector.
        return; //and return;
    }
    //int num = s[index] - '0'; //In case if array not given and string is given, then to extract number from string.
    string value = mapping[a[index]]; //extracting mapping value.
    for (int i = 0; i < value.length(); i++) //looping till length of that string value.
    {
        temp.push_back(value[i]); //pushing current character in temp string.
        solve(a, n, temp, mapping, ans, index + 1); //calling function for next index.
        temp.pop_back(); //this is simply backtracking. 
    }
}
vector<string> possibleWords(int a[], int N)
{
    vector<string> ans;
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; //creating mapping equation.
    string temp;
    int index = 0;
    solve(a, N, temp, mapping, ans, index);
    return ans;
}