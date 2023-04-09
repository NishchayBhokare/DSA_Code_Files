//Maximum Occuring Character
//GFG

#include<bits/stdc++.h>
using namespace std;

//Approach 1: Most optimised using unordered map. TC-O(N) SC-O(N)
 char getMaxOccuringChar(string str)
{
    unordered_map<char,int> mp;
    
    for(int i=0; i<str.length(); i++){
        mp[str[i]]++;
    } 
    
    int maxCount = 0;
    char ans;
    for(auto i:mp){
        if(i.second > maxCount) {
            ans = i.first;
            maxCount = i.second;
        }
        
        else if(i.second == maxCount and i.first < ans){ //This is additional if block for checking if both character's frequence is same, then check which character comes first in alphabet order, and if current character comes first i.e i.first come first then update ans to i.first.
            ans = i.first;
        }
    }
    
    return ans;
}

//Approach 2: Uaing map. TC-O(nlogn) SC-O(n).
char getMaxOccuringChar(string str)
{
    map<char,int> mp;
    
    for(int i=0; i<str.length(); i++){
        mp[str[i]]++;
    }
    
    int maxCount = 0;
    char ans;
    for(auto i:mp){
        if(i.second > maxCount) {
            ans = i.first;
            maxCount = i.second;
        }
    } 
    return ans;
}