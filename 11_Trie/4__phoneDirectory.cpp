//Phone directory
//GFG
#include<bits/stdc++.h>
using namespace std;


//Approach 1: Using Trie. TC-O(n*m) SC-O(n*m) 
 class TrieNode{
        public:
        char data;
        TrieNode *children[26];
        bool isTerminal;
        
        TrieNode(char ch){
            data = ch;
            for(int i=0; i<26; i++) children[i]=NULL;
            isTerminal = false;
        }
    };
    
    class Trie{
       public:
       
       TrieNode *root; 
       Trie(){
           root = new TrieNode('\0');
       }
       
       void insertUtil(TrieNode *root, string str){
           if(str.length() == 0){
               root->isTerminal = true;
               return;
           }
           
           TrieNode *child;
           int index = str[0] - 'a';
           
           if(root->children[index] != NULL){ //present case
               child = root->children[index];
           }
           else{ //absent case
               child = new TrieNode(str[0]);
               root->children[index] = child;
           }
           
           insertUtil(child, str.substr(1));
       }
       
       void insertWord(string str){
           insertUtil(root,str);
       }
       

//Main problem solving
    void printSuggestion(TrieNode *curr,vector<string>&temp, string prefix){
        if(curr->isTerminal){ //if we reach to terminal node then push prefix till current node in temp.
            temp.push_back(prefix);
        }
        
        TrieNode *next; //creating next
        for(char ch ='a'; ch<='z'; ch++){ //looping from a to z.
            int index = ch -'a'; //getting index
            
            if(curr->children[index] != NULL){ //present case
                next = curr->children[index]; //point next to its child
                prefix.push_back(ch); //add in prefix current character
                printSuggestion(next,temp,prefix); //and call print suggestion for next element
                prefix.pop_back(); //once return pop back character
            } 
        }
    }
    
    void getSuggestion(vector<vector<string>> &ans, string s){
        
        string prefix=""; //creating prefix string so that once we reach to terminal character we can insert this stored string into the temp vector
        
        TrieNode *prev = root; //creating prev node so that we can keep track that previous node is already traversed and move to next ones
        
        vector<string> temp; //creating temp vector so that we can insert prefix string in temp.
        int i=0;
        for(i; i<s.length(); i++){ //looping over targeted string.
            char ch = s[i]; //getting character
            prefix.push_back(ch); //pushing in prefix
            
            TrieNode * curr; //crating current node
            int index = ch - 'a'; //getting index for given charater
            
            if(prev->children[index] != NULL){ //child is present at given index case
            
                curr = prev->children[index]; //so point current to prev's child node
                printSuggestion(curr,temp,prefix); //and call printSuggestion function for getting string which are starting from character ch.
                
            }
            else{ //if absent then break.
                break;
            }

            prev = curr; //point prev to current for next iteration
            ans.push_back(temp); //push answer after every iteration
            temp.clear(); //clear temp vector.
        }
        
        for(i; i<s.size(); i++){ //if there is not any prefix then insert 0.
            temp.push_back("0");
            ans.push_back(temp);
            temp.clear();
        }
    }
    
};

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    vector<vector<string>> ans;
    Trie *t = new Trie();

    for(int i=0; i<n; i++){
        t->insertWord(contact[i]); //inserting all string into the trie
    }
    
    t->getSuggestion(ans,s); //get suggestion function called which will return ans
    
    return ans;
}




//Approach 2: Iterative approach. TC-O(m*nlogn) SC-O(m+n) 
 vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        vector<vector<string>> ans;
        string prefix = "";
        for(int i=0; i<s.length(); i++){ //m
            
            vector<string>temp;
            
            prefix += s[i]; //getting current prefix
            
            for(int j=0; j<n; j++){ //n
                string sub = contact[j].substr(0,i+1); //and checking that prefix is present in every string of contact or not.
                
                if(prefix == sub) temp.push_back(contact[j]); //if sub string and prefix is same then push that sring into temp
            }
            
            if(temp.size() == 0) temp.push_back("0"); //if size of temp equals to 0, then push string "0" into the temp
             
            sort(temp.begin(),temp.end()); //nlogn
            //then sort temp for current prefix.
            
            ans.push_back(temp); //and push into the ans vector.
        }
        
        //Removing duplicate string.
        for(int i=0; i<ans.size(); i++){
            for(int j=1; j<ans[i].size(); j++){
                if(ans[i][j] == ans[i][j-1]) ans[i][j].erase(); 
            }
        }
        return ans; //and return answer.
    }
