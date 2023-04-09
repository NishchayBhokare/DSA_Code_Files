//First non-repeating character in a stream
//gfg

#include<bits/stdc++.h>
using namespace std;


//TC-O(26*n) - > 26 for inner while loop. 
//SC-O(26) -> for map and queue
string FirstNonRepeating(string str){
string ans="";
unordered_map<char,int>mp;
queue<char>q;

for(int i=0; i<str.length(); i++){
    //step1: storing count and pusing character in queue
    char ch = str[i];
    mp[ch]++;
    q.push(ch);
    
    //step 2: pop till front character is more than once
    while(!q.empty() and mp[q.front()] > 1){
        q.pop();
    }
    
    
    //step 3: if queue is empty then non repeating character is not there, if queue is not empty then front character will be the non repeating character
    if(q.empty()) ans+='#';
    else ans+=q.front();
    }
        
    //return ans
    return ans;	    
}