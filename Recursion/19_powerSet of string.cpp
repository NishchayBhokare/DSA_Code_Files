//Find power set of given string.
//GFG
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//TC - O(2^n),  SC-  O(2^n) * O(length of each subset) = O(2^n*length of each subset).
void solve(string str,string temp,vector <string> &ans,int i){
	//Base case
	if(i >= str.length()){ //when, i equals to length of string str then base case occurs, cause i gets out of bound.
	    if(temp.length() > 0) ans.push_back(temp);//To skip condition when length of temp string equals to zero i.e empty, then no need to push into ans vector.
	    return;
	}

	//Not taking character
	solve(str,temp,ans,i+1);//not taking any element, just incrementing index i.

	//Taking character
	temp.push_back(str[i]);//here we're taking element and pushing into temp string.
	solve(str,temp,ans,i+1);//again  call solve function for next index.
}


vector<string> AllPossibleStrings(string str){
    int i=0; 
    string temp = "";
    vector<string>ans;
    solve(str,temp,ans,i);
    sort(ans.begin(),ans.end()); //sorting ans vector to get answer in lexicographical order.
    return ans;
}