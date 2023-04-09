#include<bits/stdc++.h>
using namespace std;

class TrieNode{ //creating class of trieNode type
    public:
    char data; //creating character type data which will contain alphabet
    TrieNode * children[26]; //creating trieNode array of 26 size to store its child nodes.
    bool isTerminal; //creating bool variable which shows current node is terminal or not.

    TrieNode(char ch){
        this->data = ch; //getting character
        for(int i=0; i<26; i++) children[i]=NULL; //initialising child nodes as null.
        isTerminal = false; //and pointing isTerminal as false.
    }
};

class Trie{ //creating class of type trie.
    public:
    TrieNode *root; //creting root of trieNode type

    Trie(){ 
        root = new TrieNode ('\0'); //initialising root node with null.
    }


//Inserting word into trie.
    void inputUtil(TrieNode *root, string word){
        if(word.length() == 0){ //if we traverse over all character then length of string will be 0.
            root->isTerminal = true; //so mark currnet character as terminal node and return
            return;
        }

        TrieNode *child; //creating child pointer of trienode typ
        int index = word[0] - 'A'; //getting index for given character

        if( root->children[index] != NULL ){ //if current character is already present then shift child to its children node i.e on  current character.
            child = root->children[index];
        }
        else{ //If current character is not present then create trieNode for current character and connect that child with root.
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //Recursive call
        inputUtil(child, word.substr(1)); //recursive call, for rest sub string that is except first character, call for rest.
    }

//calling inputUtil function.
    void inputWord(string word){
        inputUtil(root, word);
    }

//Search functionaltiy
    bool searchUtil(TrieNode *root, string word){
        if(word.length() == 0){ //if we traverse over all characters
            return root->isTerminal; //and return true if current node is terminal node else return false.
        }

        TrieNode *child;

        int index = word[0] - 'A';

        if(root->children[index] != NULL){ //present
            child = root->children[index];
        }
        else{ //absent
            return false; //if character is not present then return false
        }

        //Recursive call
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
    }


//Removal i.e Deletion in Trie.
    void deleteUtil(TrieNode *root, string word){
        if(word.length() == 0){ //once traverse all characters
            root->isTerminal = false; //then convert current node as terminal to non terminal node i.e make false.
            return;
        }

        TrieNode *child;
        int index = word[0] - 'A';

        if(root->children[index] != NULL){ //present case
            child = root->children[index]; 
        }
        else{
            return; //if character is not present then simply return
        }

        //Recursive call
        deleteUtil(child,word.substr(1));
    }

    void deleteWord(string word){
        deleteUtil(root, word);
    }
};

int main(){

    Trie *t = new Trie();
    t->inputWord("ABCD");
    t->inputWord("DO");
    t->inputWord("TIME");

    cout<<"Before Deleting "<<endl;
    if(t->searchWord("TIME")){
        cout<<"Word is present "<<endl;
    }
    else{
        cout<<"Word is not present "<<endl;
    }

    t->deleteWord("TIME");

    cout<<endl<<"After Deleting "<<endl;
    if(t->searchWord("TIME")){
        cout<<"Word is present "<<endl;
    }
    else{
        cout<<"Word is not present "<<endl;
    }

    return 0;
}