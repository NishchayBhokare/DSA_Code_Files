//It is multi source shortest path algorithm. -> saw SS for Floyd warshal algo. i have taken ss.
Dijkstra's Shortest Path algorithm and Bellman-Ford algorithm are single-source shortest path algorithms 
where we are given a single source node and are asked to find out the shortest path 
to every other node from that given source. 

But in the Floyd Warshall algorithm, we need to figure out the shortest distance from each node 
to every other node. Basically, the Floyd Warshall algorithm is a multi-source shortest path algorithm 
and it helps to detect negative cycles as well. 
The shortest path between node u and v necessarily means the path(from u to v) 
for which the sum of the edge weights is minimum.
//It helps to detect negative cycle.

//TC-O(N3)
//Instead of this..we can use dijkstra algo..on every node to find out shortest path from every node..which
// take TC-O(V*(ElogV)) which is still better than floyd warshal algo..but remember dijkstra will fail in -ve weight cycle.
//floyd will not fail.

//Appraoch 1: algo in single loop.
 void shortestDistance(vector<vector<int>>& mat) {
    // Code here
    int n = mat.size();
    
    for(int via = 0; via < n; via++){ //as we have to find shortest distance from every node to every other node.
    //so we're traversing via every node..and updating distance. suppose, to go from i to j,
    //even if there is direct path i to j. we will go by i to via and then via to j.
    //why these..because to find out min distnace among all possible ways to reach that j node we need to do this.

        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){

                if(mat[row][via] != -1 && mat[via][col] != -1){ //handling -ve cases..if any of the index when via 
                //is considering is -ve then skip. //suppose there is not path from row to via or via to col then how can we go..so skip this iteration.
                    
                    int viaSum = mat[row][via] + mat[via][col]; //calculating from distance (row to via and via to col)
                    
                    if(mat[row][col] == -1) 
                    //if row col having value -1 then it means..there is not direct path from row to col.
                    //but there is path from row to via and then via to col. so store viasum distance as it is.
                        mat[row][col] = viaSum;
                    else{
                        mat[row][col] = min(mat[row][col],viaSum); //else take minimum of rowcol and viasum.
                    }
                }
                    
            }
        }
    }
    
}

//Approach 2: to get avoid from adding if condition for -1..we can solve this question by converting -1 to 1e9 and
//at last agin convert 1e9 to -1.
 void shortestDistance(vector<vector<int>>& mat) {
    int n = mat.size();
    
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            
            if(mat[row][col] == -1)
                mat[row][col] = 1e9; //converting -1 to infinity
            
            if(row==col)
                mat[row][row] = 0; //putting diagonal value as 0.
        }
    }
    
    for(int via = 0; via < n; via++){
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){

                int viaSum = mat[row][via] + mat[via][col]; 
                mat[row][col] = min(mat[row][col],viaSum); //now no need to add if conditions
            }
        }
    }
    
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            
            if(mat[row][col] == 1e9) //retriving infinity to -1.
                mat[row][col] = -1;
            
        }
    }
    
}