//GFG
//Longest Common Prefix in an Array
#include<bits/stdc++.h>
using namespace std;

//Approach 1: Using Trie. 
//TC-O(N*M) N->is total number of strings. M->is length of particular string.
//SC-O(M). 
//Analogy if any node have more than 1 child or if current root is terminal character node for any of the string then return or break.
//else push current character into the answer string.

 class TrieNode{ //creating trie node
        public:
        char data;
        TrieNode *children[26];
        bool isTerminal;
        int childrenCount;
        
        TrieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++) children[i]=NULL;
            isTerminal = false;
            childrenCount = 0;
        }
    };
    
class Trie{
    public:
    
    TrieNode *root;
    Trie(){
        root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode *root, string str){ //inserting string
        
        if(str.length() == 0){
            root->isTerminal = true;
            return;
        }
        
        int index = str[0] - 'a';
        TrieNode *child;
        
        if(root->children[index] != NULL){ //if current character is present
            child = root->children[index]; 
        }
        else{ //if not present then simply create node for current character
            child = new TrieNode(str[0]);
            root->children[index] = child; 
            root->childrenCount++; //increment children count for current root.
        }
        
        insertUtil(child,str.substr(1));
    }
    
    void insertWord(string str){
        insertUtil(root,str);
    } 

    

    //we can find prefix...recursively also.
    void findPrefixInTri(TrieNode * root,string str, string &prefixAns){
        if(root->childrenCount != 1 || root->isTerminal){
            return;
        }

        TrieNode * child;
        int index = str[0] - 'a';
        if(root->children[index] != NULL){
            child = root->children[index];
            char ch = child->data;

            prefixAns.push_back(ch);
        }
        else
            return;

        findPrefixInTri(child, str.substr(1), prefixAns);
    }
    
    //Iterative approach.
    void CheckForPrefix(string first, string &ans){
        
        for(int i=0; i<first.length(); i++){ //looping over first string
            
            char ch = first[i]; //getting character 
            if(root->childrenCount == 1){ //if count of children is equal to 1 then,
                int index = ch - 'a';
                ans.push_back(ch); //store ith character into the ans
                root = root->children[index]; //and shift root to its children
            }
            else{
                return; //if children count is greater than 1 then return.
            }
            
            if(root->isTerminal) return; //if current root is terminal node for any of the string then return.
        }
    }   
};

string longestCommonPrefix (string arr[], int N)
{
    string ans="";
    
    Trie *t = new Trie();
    
    for(int i=0; i<N; i++){ //looping over given string 
        t->insertWord(arr[i]); //and inserting every string in trie.
    }
    
    string first = arr[0]; //storing first string from string array
    
    t->CheckForPrefix(first,ans); //checking for prefix string.
    
    if(ans.length() == 0) return "-1"; //if size of ans equals to 0 then simply return -1.
    return ans; //return answer string.
}


//Approach 2: optimised approach but we're not using trie here.
//TC-O(N*M) N->is total number of strings. M->is length of particular string.
//SC-O(1).
//Analogy: first checking ith character of every string is same or not, if same then push into ans string else break and return.
string longestCommonPrefix (string arr[], int N)
{
    string ans;
    
    for(int i=0; i<arr[0].length(); i++){ 
        char ch = arr[0][i]; //getting ith character of 0th string.
        
        bool flag = true; //initially flag is true
        
        for(int j=1; j<N; j++){ //looping from first index string till last for every ith character.
            
            if(i >= arr[j].length() || ch != arr[j][i]){ //if character is not equal with jth string or if jth string is less than 0th string then flag will be false and break.
                flag = false;
                break;
            }
            
        }
        
        if(flag == false) break; //after iteration of ith character of every stirng in string arr[], check flag is true or not. if flag is false that means there is no any common character so break form the loop.
        else ans.push_back(ch); //if flag is true that means ch is common character so push into ans string
    }
    
    if(ans.size() == 0) return "-1"; //if size of ans is 0 then simply return -1.
    return ans; //else return ans string.
}

//not much better solution ...but ya this is also solution.
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = arr[0];

    for(int i = 1; i<arr.size(); i++){
        string str = arr[i];
        int j = 0;

        while(j<ans.size() && j<str.size()){
            if(ans[j] != str[j]){
             break;
            }
            j++;
        }

        if(j<ans.size())
            ans.erase(j);
    }

    return ans;
}
