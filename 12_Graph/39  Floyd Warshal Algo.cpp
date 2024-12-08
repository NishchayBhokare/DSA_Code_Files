//It is multi source shortest path algorithm.
//It helps to detect negative cycle.

//TC-O(N3)
//Instead of this..we can use dijkstra algo..on every node to find out shortest path from every node..which
// take TC-O(V*(ElogV)) which is still better than floyd warshal algo..but remember dijkstra will fail in -ve weight cycle.
//floyd will not fail.

//Appraoch 1: algo in single loop.
 void shortestDistance(vector<vector<int>>& mat) {
    // Code here
    int n = mat.size();
    
    for(int via = 0; via < n; via++){
        for(int row = 0; row<n; row++){
            for(int col = 0; col<n; col++){

                if(mat[row][via] != -1 && mat[via][col] != -1){ //handling -ve cases..if any of the index when via 
                //is considering is -ve then skip.
                    
                    int viaSum = mat[row][via] + mat[via][col];
                    
                    if(mat[row][col] == -1) //if rowcol have value -1..then put whatever value viaSum has.
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