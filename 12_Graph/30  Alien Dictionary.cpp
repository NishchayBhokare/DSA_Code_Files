 //GFG 
 
//Question is updated, now they haven't given k. so it's become more interesting.
//Approach 1: Using BFS, Topological Sort. TC-O(V+E)
class Solution {
  public:
    string findOrder(vector<string> &words) {
      
        vector<vector<int>>adj(26); //as we don't know k, so initilize vectors with 26, because
        //max 26 letters are there in alphabet series.
        vector<int>indegree(26,0);
        
        vector<int>exist(26,0); //used to track character present or not, it will help while pushing in queue
        //because to track which element exist and whose indegree is zero.
        
        for(auto str:words){
            for(auto ch:str){
                exist[ch -'a']=1; //if exist marking as 1.
            }
        }
       
        
        for(int i=0; i<words.size()-1; i++){
            
            string s1 = words[i], s2=words[i+1];
            int len=min(s1.size(), s2.size());
            
            for(int j=0; j<len; j++){
                if(s1[j] != s2[j]){
                    
                    int u = s1[j]-'a';
                    int v = s2[j]-'a';
                    
                    adj[u].push_back(v);
                    indegree[v]++; //incrementing indegree.
                    break;
                }
            }
        }
     
        
        queue<int>q;
        for(int i=0; i<26; i++){
            
            if(exist[i] and indegree[i] == 0){ //if exist and indegree is 0 for that element.
                q.push(i);
            }
        }
        
        string ans="";
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            ans += char('a'+node); //convert int to char.
            
            for(auto nbr:adj[node]){
                
                indegree[nbr]--;
                
                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
        cout<<ans<<endl;
 
        for(int i=0; i<26; i++){ //checking if cycle is present or not.
            if(exist[i] and indegree[i] != 0) //if element is exit but still its indegree is
            //not equal to zero then return empty string.
                return "";
        }
        return ans;
    }
};

//Approach 2: Using DFS.
class Solution {
  public:
    bool solve(int node, vector<vector<int>>&adj, vector<int>&visited, string &ans,
        vector<int>&dfsVisited){
        
        visited[node]=1;
        dfsVisited[node]=1;
        
        for(auto nbr:adj[node]){
            
            if(!visited[nbr]){
               if(solve(nbr,adj,visited,ans, dfsVisited) == false)
                return false;
            }
            else if(dfsVisited[nbr]){ //if nbr is already visited, that means cycle is presnet so
                //return false, i.e  linear ordering is not possible.
                return false;
            }
        }
        
        dfsVisited[node]=0;
        ans+= char(node +'a');
        return true;
    }
  
    string findOrder(vector<string> &words) {
      
        vector<vector<int>>adj(26);
 
        vector<int>exist(26,0); //used to track character present or not.
        
        for(auto str:words){
            for(auto ch:str){
                exist[ch -'a']=1;
            }
        }
       
        
        for(int i=0; i<words.size()-1; i++){
            
            string s1 = words[i], s2=words[i+1];
            int len=min(s1.size(), s2.size());
            
            for(int j=0; j<len; j++){
                if(s1[j] != s2[j]){
                    
                    int u = s1[j]-'a';
                    int v = s2[j]-'a';
                    
                    adj[u].push_back(v);
                    break;
                }
            }
        }
        
        string ans="";
        vector<int>visited(26);
        vector<int>dfsVisited(26);
        for(int i=0; i<26; i++){
            
            if(exist[i] and !visited[i]){
                if(!solve(i, adj,visited, ans, dfsVisited))
                    return "";
            }
        }
        
        
        reverse(ans.begin(), ans.end());
      
        return ans;
    }
};






//As we know..question is asking to ordering characters..that means...something before something case.
//so in this case we can use topological sort.


//Approach 1: using BFS toplogical sort. 
 string findOrder(vector<string> dict, int k) {
    vector<vector<int>>adj(k);

    for(int i = 0; i<dict.size()-1; i++){ //looping over dictionary array and taking two strings.
        string first = dict[i];
        string second = dict[i+1];
        
        int len = min(first.size(), second.size()); //looping till minimum length of string.
        
        for(int i = 0; i<len; i++){
            if(first[i] != second[i]){
                
                int node = first[i] - 'a'; //getting integer value from character so that we can store it in adjacency list.
                int nbr = second[i] - 'a';
                
                adj[node].push_back(nbr); //create link from node to nbr. as node came before nbr.
                break;
            }
        }
    }
    
    
    //Now, just find toplogical order from this created adjacency list.
    vector<int>indegree(k,0);
    queue<int>q;
    
    //find indegree
    for(int i = 0; i<adj.size(); i++){
        for(auto nbr:adj[i]){
            indegree[nbr]++;
        }
    }
    
    
    //push element in queue which has indegree as 0.
    for(int i = 0; i<indegree.size(); i++){
        if(indegree[i] == 0)
            q.push(i);
    }
    
    
    string ans = "";
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        //converting integer to character and stored into the answer string.
        char ch = char(node + 'a'); 
        ans.push_back(ch);
        
        for(auto nbr:adj[node]){
            indegree[nbr]--;
            
            if(indegree[nbr] == 0){
                q.push(nbr);
            }
        }
    }
    
    return ans;
}


//Approach 2: simple way..using DFS toplogical sort. 
void solve(int node, vector<vector<int>>&adj, vector<bool>&visited, string &ans){
    
    visited[node] = true;
    
    for(auto nbr:adj[node]){
        if(!visited[nbr]){
            solve(nbr,adj,visited,ans);
        }
    }
    
    //just before returning make sure
    char ch = node + 'a';
    ans.push_back(ch);
}

    string findOrder(vector<string> dict, int k) {
    
    vector<vector<int>>adj(k);
    
    for(int i = 0; i<dict.size()-1; i++){
        string first = dict[i];
        string second = dict[i+1];
        
        int len = min(first.size(), second.size());
        
        //preparing graph.
        for(int i = 0; i<len; i++){
            if(first[i] != second[i]){
                
                int node = first[i] - 'a';
                int nbr = second[i] - 'a';
                
                adj[node].push_back(nbr);
                break;
            }
        }
    }
    
    string ans = "";
    vector<bool>visited(k,false); //now here k is acting as number of nodes.
    for(int i = 0; i<k; i++){ //so just do normal dfs now. simple question.
        if(!visited[i]){
            solve(i,adj,visited,ans);
        }
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}