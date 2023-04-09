//Insert and serach in trie.
//GFG

#include<bits/stdc++.h>
using namespace std;
struct TrieNode {
    struct TrieNode *children[26];
    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

//For searching -> TC-O(string lenght (l)) SC-O(length).
//For insertion -> TC-O(l) SC-O(length)
void insert(struct TrieNode *root, string key)
{
    if(key.length() == 0){
        root->isLeaf = true;
        return;
    }
    
    TrieNode *child;
    int index = key[0] - 'a';
    
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        child = new TrieNode();
        root->children[index] = child;
    }
    
    //Recursive call
    insert(child, key.substr(1));
}


//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    if(key.length() == 0){
        return root->isLeaf;
    }
    
    TrieNode *child;
    int index = key[0] - 'a';
    
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return false;
    }
    
    return search(child, key.substr(1));
}
