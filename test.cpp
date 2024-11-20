#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char d){
        data = d;
        for(int i=0; i<26; i++) children[i]=NULL;
        isTerminal = false;
    }  

    void insertInTrieNode(TrieNode * root, string str){
        if(str.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = str[0] - 'a';

        TrieNode *child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(str[0]);
            root->children[index] = child;
        }

        insertInTrieNode(child,str.substr(1));
    }

    bool searchInTrieNode(TrieNode * root, string str){
        if(str.size() == 0){
            return  root->isTerminal;
        }

        int index = str[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL){
            //present
            child = root->children[index];
        }
        else return false;

        return searchInTrieNode(child,str.substr(1));
    }

    void deleteInTrieNode(TrieNode *root, string str){
        if(str.size() == 0){
            root->isTerminal = false;
            return;
        }

        int index = str[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else 
            return;
        
        deleteInTrieNode(child,str.substr(1));
    }
};

class Trie{
    public:
    TrieNode * root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insert(string str){
        root->insertInTrieNode(root,str);
    }

    bool search(string str){
        return root->searchInTrieNode(root,str);
    }

    void deleteStr(string str){
        root->deleteInTrieNode(root,str);
    }
};


int main(){
    Trie * tr = new Trie();
    tr->insert("nishu");
    tr->insert("nish");
    cout<<"is present "<<tr->search("nishaa")<<endl;
    tr->deleteStr("nish");
    cout<<"is present "<<tr->search("nish")<<endl;
}




5 2 1 4 6 3 9 8 7
3 6 9 8 5 7 2 4 1
4 8 7 9 1 2 3 5 6
7 5 8 2 4 9 6 1 3
6 4 3 5 7 1 8 9 2
9 1 2 3 8 6 4 7 5
8 7 4 6 2 5 1 3 9
1 3 6 7 9 4 5 2 8
2 9 5 1 3 8 7 6 4


//my solution.
5 2 6  4 1 3  9 7 8
3 1 9  8 5 7  6 4 2
4 8 7  9 6 2  3 5 1

6 5 1  2 8 9  4 3 7
2 4 3  5 7 1  8 6 9
7 9 8  3 4 6  2 1 5

8 7 5  6 2 4  1 9 3
1 3 4  7 9 8  5 2 6
9 6 2  1 3 5  7 8 4






//new ........................................................................
// string longestCommonPrefix(vector<string> &arr, int n)
// {
//     // Write your code here
//     string ans = arr[0];

//     for(int i = 1; i<arr.size(); i++){
//         string str = arr[i];
//         int j = 0;

//         while(j<ans.size() && j<str.size()){
//             if(str[j] != ans[j]){
//               break;
//             }
//             j++;
//         }

//         if(j < ans.size())
//             ans.erase(j);
//     }

//     return ans;
// }

class TrieNode{
    public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char d){
        data = d;
        isTerminal = false;
        for(int i =0; i<26; i++)
            children[i] = NULL;
    }

    void insertInTrieNode(TrieNode *root, string str){
        if(str.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = str[0] - 'a';
        TrieNode *child;

        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            child = new TrieNode(str[0]);
            root->children[index] = child;
        }

        insertInTrieNode(child, str.substr(1));
    }
    
    void findPrefixInTri(TrieNode * root, string &prefixAns){
        if(root->isTerminal){
            return;
        }

        int count = 0;
        char ch;
        TrieNode * child;
        for(int i = 0; i<26; i++){
            if(root->children[i] != NULL){
                count++;
                child = root->children[i];
                ch = child->data;
            }
        }

        if(count > 1) return;
        else prefixAns+=ch;

        findPrefixInTri(child, prefixAns);
    }
};

class Trie{
    public:
    TrieNode *root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insert(string str){
        root->insertInTrieNode(root,str);
    }

    void findPrefix(string &prefixAns){
        root->findPrefixInTri(root,prefixAns);
    }
};


string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie * t = new Trie();


    for(int i = 0; i<arr.size(); i++){
        t->insert(arr[i]);
    }

    string prefixAns = "";
    t->findPrefix(prefixAns);

    return prefixAns;
}










