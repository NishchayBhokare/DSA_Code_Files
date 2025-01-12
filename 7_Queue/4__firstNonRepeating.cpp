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
    //step1: storing count and pushing character in queue
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


//Approach 2: similar like above only...but here..we're pushing character into queue
//only if it's not repeating character.
string FirstNonRepeating(string &s) {

    unordered_map<char, int>charFreq;
    queue<char>q;
    string ans;
    
    for(int i=0; i<s.length(); i++){
        
        if(charFreq.find(s[i]) == charFreq.end()){ //if character is not present in map that menas. it's not 
        //repeating character so push this character in queue and answer. also update frequency of character to 1.
            
            q.push(s[i]);
            ans.push_back(q.front());
            charFreq[s[i]] = 1;
        }
        else{ //if character is already present in map. that means. this is repeating character.
            
            charFreq[s[i]]++; //first increment it's frequency.
            
            while(!q.empty() && charFreq[q.front()] > 1) //then check for non repeating character from map.
                q.pop();
                
            if(q.empty()) //if we don't find non repeating character then add # in ans.
                ans.push_back('#');
            else
                ans.push_back(q.front()); //if found then add that non repeating character.
        }
    }
    
    return ans;
}