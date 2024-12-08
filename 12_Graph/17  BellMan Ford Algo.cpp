//GFG

//we can find shortest path by bellman ford algo..dijkstra fails..when -ve weights are there..but bellman
//can be used for this..condition is..there should not be negative weightage cycle..else u will find in infinite loop.
//also..with bellman ford algo..u can find..-ve weightage cycle is present or not.

//We required vertext -1 iteration to fill and reach every node for shortest distance.
//Algorithm says..do numerb of vertex - 1 iterations..to check..distance for u to v can be update or not..for v node.
//on all the edges...
//after completion of all these n-1 iterations.. now check again for only one iteration on all the edges..and verify..
//for any node..is distance getting updated or not..if it's getting updating..then -ve cycle present in graph..so can't find
//answer..return -1.
//else return vector which stores shortest parth.
//TC(V*E)
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
         vector<int> dist(V,1e8);
            dist[src] = 0;
        
            for(int i = 0; i<V-1; i++){ //do n-1 iterations.
                for(int j = 0; j<edges.size(); j++){
                    int u = edges[j][0];
                    int v = edges[j][1];
                    int w = edges[j][2];
        
                    if(dist[u]!= 1e8 && (dist[u] + w < dist[v])){
                        dist[v] = dist[u] + w;
                    }
                }
            }
            
            bool flag = false;
            for(int j = 0; j<edges.size(); j++){ //do one more time iteration.
                int u = edges[j][0];
                int v = edges[j][1];
                int w = edges[j][2];
    
                if(dist[u]!= 1e8 && (dist[u] + w < dist[v])){
                    flag = true;
                }
            }
            
            if(flag) return {-1}; //now if flag becomes true..that means..-ve cycle is there so return -1.
            
            return dist; //else return distnace vector which stores shortest distance;
    }