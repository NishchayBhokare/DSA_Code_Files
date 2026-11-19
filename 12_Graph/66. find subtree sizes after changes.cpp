//Leetcode.

class Solution {
public:
    void findAncestor(int &node, vector<vector<int>>& adj, string &s,
                      vector<int>& charToNode, vector<int>& parent) {

        int ind = s[node] - 'a';

        // Store the previously mapped node to restore it during backtracking.
        int prevNode = charToNode[ind];

        // If the same character already exists in the current DFS path,
        // the mapped node is the closest ancestor having this character.
        if(charToNode[ind] != -1) {
            parent[node] = charToNode[ind];
        }

        // Update the mapping with the current node.
        charToNode[ind] = node;

        // Explore all children using the original tree.
        for(auto nbr : adj[node]) {
            findAncestor(nbr, adj, s, charToNode, parent);
        }

        // Backtrack: restore the previous mapping so that other branches
        // do not consider this node as their ancestor.
        charToNode[ind] = prevNode;
    }

    void getSize(int &node, vector<vector<int>>& adj, vector<int>& sizeArr) {

        // Process all children before calculating the current node's size.
        for(auto nbr : adj[node]) {

            getSize(nbr, adj, sizeArr);

            // Add the entire subtree size of the child to the current node.
            sizeArr[node] += sizeArr[nbr];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = s.length();
        vector<vector<int>> adj(n);

        // Build the adjacency list of the original tree.
        for(int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        // Find the closest matching ancestor for every node
        // and update its parent using DFS + backtracking.
        vector<int> charToNode(26, -1);
        int node = 0;
        findAncestor(node, adj, s, charToNode, parent);

        // Build the adjacency list of the modified tree.
        vector<vector<int>> modifiedAdj(n);

        for(int i = 1; i < n; i++) {
            modifiedAdj[parent[i]].push_back(i);
        }

        // Initially, every node contributes 1 to its own subtree.
        vector<int> sizeArr(n, 1);

        // Calculate subtree sizes using postorder DFS.
        node = 0;
        getSize(node, modifiedAdj, sizeArr);

        return sizeArr;
    }
};


//Appraoch 2: Just small change, instead of vector, we have used map. but vector approach is better.
class Solution {
public:
    void findAncestor(int &node, vector<vector<int>>&adj, string &s, unordered_map<char,int>&charToNode, vector<int>&parent){

        int prevNode = -1;
        if(charToNode.find(s[node]) != charToNode.end()){ //if current node character is already present, that means we found ancestor.
            parent[node] = charToNode[s[node]];
            prevNode = charToNode[s[node]];
        }
        
        charToNode[s[node]]=node;

        for(auto nbr:adj[node]){
            findAncestor(nbr,adj,s,charToNode,parent);
        }
        
        if(prevNode != -1) charToNode[s[node]]=prevNode;
        else charToNode.erase(s[node]);
    }

    void getSize(int &node, vector<vector<int>>&adj, vector<int>&sizeArr){

        for(auto nbr:adj[node]){
            getSize(nbr,adj,sizeArr);
            sizeArr[node] += sizeArr[nbr];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        
        int n=s.length();
        vector<vector<int>>adj(n);

        //create adjacency list.
        for(int i=1; i<n; i++){
            adj[parent[i]].push_back(i);
        }

        //find ancestor and update parent array.
        unordered_map<char,int>charToNode;
        int node = 0;
        findAncestor(node,adj,s,charToNode,parent);

        vector<vector<int>>modifiedAdj(n);
        //create adjacency list.
        for(int i=1; i<n; i++){
            modifiedAdj[parent[i]].push_back(i);
        }


        //get size.
        vector<int>sizeArr(n,1);
        node = 0;
        getSize(node,modifiedAdj,sizeArr);

        return sizeArr;
    }
};