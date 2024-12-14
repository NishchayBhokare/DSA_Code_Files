//Find power set of given string.
//GFG
	// Input : str = "abc"
	// Output: a ab abc ac b bc c
	// Explanation : There are 7 subsequences that 
	// can be formed from abc.
	
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


//subsequences using bit manipulation 
vector<string> subsequences(string str){
	vector<string> ans;
	int num = pow(2,str.length()) - 1; //we are creating num which will represent to given string. suppose 
	//stirng of size 3 then digits in num will be 3 i.e 111.
	//logic is traversing from 1 to <= num..and for every value checking it's binary repersentation
	//if bit is 1 then take ith character from string..else skip.

	for(int i = 1; i<= num; i++){
		int val = i, j = 0;
		string temp;
		while(val){
			if(val & 1) temp+=str[j];
			
			val = val>>1;
			j++;
		}
		ans.push_back(temp); //on every ith iteation...push value in ans vector of temp.
	}
	return ans;
}
//logic is ->
//001=>1 will be tagged to a
//010=>2 will be tagged to b
//011=>3 will be tagged to ab
//100=>4 will be tagged to c
//101=>5 will be tagged to ac
//110=>6 will be tagged to bc
//111=>7 will be tagged to aaa