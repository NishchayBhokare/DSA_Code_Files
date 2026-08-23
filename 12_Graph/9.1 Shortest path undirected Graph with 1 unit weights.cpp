
//Approach: Using standard BFS Algorithm. TC-O(N+2E) SC-O(N+E)
//We can use standard way instead of dijktra because all weights are 1.
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        
        vector<vector<int>>adj(N);

        for(auto m:edges){
            int u=m[0],v=m[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>distance(N,INT_MAX);
        queue<int>q;

        q.push(0);
        distance[0]=0;

        while(!q.empty()){

            int node = q.front();
            int dist = distance[node];

            q.pop();

            for(auto nbr:adj[node]){

                if(dist+1 < distance[nbr]){
                    distance[nbr]=dist+1;
                    q.push(nbr);
                }
            }
        }

        for(int i=0; i<N; i++){
            if(distance[i]==INT_MAX)
                distance[i]=-1;
        }
        return distance;
    }
};



























