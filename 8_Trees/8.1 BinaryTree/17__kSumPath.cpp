//k Sum paths problem GFG.
//GFG
// https://www.geeksforgeeks.org/problems/k-sum-paths/1

//Approach 1: Optimised Approach. TC-O(N) SC-O(N) - Solve using prefix sum logic.
void solve(Node *root,int sum, int k, unordered_map<int,int>&mp, int &count){
    if(root == NULL) return;
    
    sum+=root->data;
    
    if(mp.find(sum-k) != mp.end()){ //if removal sum we found in map. then we can increment 
    //count by frequency of removal sum.
        count+=mp[sum-k];
    }
    
    mp[sum]++; //increment frequency for current sum.
    
    solve(root->left,sum,k,mp,count);
    solve(root->right,sum,k,mp,count);
    
    mp[sum]--; //backtrack. once current path done then backtrack. means decrement 
    // frequency of its sum. so that..we won't consider this in other paths.
}

int sumK(Node *root, int k) {

    unordered_map<int,int>mp;
    mp[0]=1; //we have added freuency of zero sum as 1. becasue we need to make sure..if 
    //sum 
    int sum=0, count=0;
    
    solve(root,sum,k,mp,count);
    return count;
}

//Approach 2: Iterative approach. TC - O(N2) SC-O(N)
int count = 0;
void solve(Node *root,int k,vector<int> path){
    if(root == NULL) return;
    
    path.push_back(root->data);
    
    solve(root->left,k,path);
    solve(root->right,k,path);
    
    int sum = 0;
    
    for(int i=path.size()-1; i>=0; i--){ //calculating all path on every node. after getting 
    //path till that node. //here we're doing this for every node. when left and right computation done.

        sum += path[i]; //then iterate over current path from back side. 
        // cause sum path can be formed anywhere between path.
        if(sum == k) count++; //if sum equals to k then increment count
    }
}
    

int sumK(Node *root,int k)
{ 
    vector<int> path;
    solve(root,k,path);
    return count;
}



//Approach 2: Recursive approach TC-O(N2) SC-O(N) 
//In this approach for every node check sum path
int count = 0;
void solve2(Node *root,int k,int sum){
    if(root == NULL) return;
    
    sum += root->data;
    if(sum == k) count++; //if current path is equals to k so increment count.
    
    solve2(root->left,k,sum);
    solve2(root->right,k,sum); 
}
    
void solve1(Node *root,int k){
    if(root == NULL) return;
    
    solve2(root,k,0); //checking for every node path sum, i.e from current node path is exist or not
    
    solve1(root->left,k);
    solve1(root->right,k);
}


int sumK(Node *root,int k)
{ 
    solve1(root,k);
    return count;
}
