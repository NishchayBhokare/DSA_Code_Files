
//Approach 1: Most Optmised Approach. TC-O(N) SC-O(N)

// The idea is to use Kahn's Algorithm to remove all cells that cannot be part of a cycle. 
// A cell with indegree 0 cannot belong to any cycle, so we remove it and decrease the indegree 
// of the cell it points to. 

// We continue this process until no more cells can be removed. The cells that remain must 
// belong to cycles, so we traverse each remaining cycle, calculate its sum, and keep the maximum 
// cycle sum.


class Solution {
  public:
  
    void solve(int node, vector<int>&edge, vector<int>&visited, int &sum){
        
        visited[node]=1;
        sum+=node;
        
        int nbrNode = edge[node];

        if(!visited[nbrNode])
            solve(nbrNode,edge,visited,sum);
    }
  
    int largestSumCycle(vector<int>& edge) {

        int n = edge.size();
        vector<int>adj(n), indeg(n,0), visited(n,0);
        
        for(int i=0; i<n; i++) {
    
            if(edge[i] != -1)
                indeg[edge[i]]++;
        }
        
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0){
                q.push(i);
                visited[i]=1;
            }
        }
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            int nbrNode = edge[node];
            
            if(nbrNode == -1) continue;
            
            indeg[nbrNode]--;
            
            if(indeg[nbrNode] == 0){
                q.push(nbrNode);
                visited[nbrNode]=1;
            }
        }
        
        
        int maxSum=-1;
        for(int i=0; i<n; i++){
            
            if(!visited[i]){
                int sum=0;
                solve(i,edge,visited,sum);
                maxSum = max(maxSum,sum);
            }
        }
        
        return maxSum;
    }
};

//Approach 1.1: In case if you want to see solution with adj list.
class Solution {
  public:
  
    void solve(int node, vector<int>&adj, vector<int>&visited, int &sum){
        
        visited[node]=1;
        sum+=node;
        
        int nbrNode = adj[node];

        if(!visited[nbrNode])
            solve(nbrNode,adj,visited,sum);
    }
  
    int largestSumCycle(vector<int>& edge) {

        int n = edge.size();
        vector<int>adj(n), indeg(n,0), visited(n,0);
        
        for(int i=0; i<n; i++) {
            adj[i] = edge[i];
        
            if(edge[i] != -1)
                indeg[edge[i]]++;
        }
        
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0){
                q.push(i);
                visited[i]=1;
            }
        }
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            
            int nbrNode = adj[node];
            
            if(nbrNode == -1) continue;
            
            indeg[nbrNode]--;
            
            if(indeg[nbrNode] == 0){
                q.push(nbrNode);
                visited[nbrNode]=1;
            }
        }
        
        
        int maxSum=-1;
        for(int i=0; i<n; i++){
            
            if(!visited[i]){
                int sum=0;
                solve(i,adj,visited,sum);
                maxSum = max(maxSum,sum);
            }
        }
        
        return maxSum;
    }
};