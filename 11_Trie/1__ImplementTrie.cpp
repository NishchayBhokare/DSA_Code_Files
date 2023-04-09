//Implement trie 
//Coding ninja

#include<bits/stdc++.h>
using namespace std;

class TrieNode{ //simply creating trie node
    public:
        char data;
        TrieNode *children[26];
        bool isTerminal;

        TrieNode(char ch){
            this->data = ch;
            for(int i=0; i<26; i++) children[i] = NULL;
            isTerminal = false;
        }
};

class Trie {
public:

    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
    void insertUtil(TrieNode *root, string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        TrieNode *child;
        int index = word[0] - 'a';

        if(root->children[index] != NULL){ //presnt case
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursive call
        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root,word);
    }


    /** Returns if the word is in the trie. */
    bool searchUtil(TrieNode * root, string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        TrieNode *child;
        int index = word[0] - 'a';

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        //Recursive call
        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }


    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWithUtil(TrieNode *root, string prefix){
        if(prefix.length() == 0){ //if we reach till here that means given prefix is present so return true
            return true;
        }

        TrieNode *child;
        int index = prefix[0] - 'a';

        if(root->children[index] != NULL){ //present.
            child = root->children[index];
        }
        else{ //if current character is not presnt in trie, then return false
            return false;
        }


        //Recursive call
        return startsWithUtil(child, prefix.substr(1));
    }
    
    bool startsWith(string prefix) {
        return startsWithUtil(root,prefix);
    }
};
