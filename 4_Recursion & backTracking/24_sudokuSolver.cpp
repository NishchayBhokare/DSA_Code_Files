

//Approach : TC-O(9^m (m is empty cells)) SC-O(1 i.e max 9 * 9  = 81 calls stack can possible)
//Logic is for every cell..checking can we insert values from 1 to 9...if yes..then insert
//and move to next recursive call..if not..then return false;.

 bool isSafe(int row, int col, int val, int grid[N][N]){
        for(int i=0; i<N; i++){
            
            //Checking for row
            if(grid[row][i] == val) 
                return false;
            
            
            //checking for col 
            if(grid[i][col] == val) 
                return false;
            
            
            //checking for 3 * 3 matrix.
            int newRow = 3 * (row/3) + i/3; //doing i divide by three to make i in range of 3 * 3.
            int newCol = 3 * (col/3) + i%3; //same here..

            if(grid[newRow][newCol] == val) 
                return false;
        }
        
        return true;
    }
    
bool SolveSudoku(int grid[N][N])  
{ 
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++){
            
            if(grid[row][col] == 0){ //if we get empty space.

                for(int val = 1; val<=9; val++){
                    if(isSafe(row,col,val,grid)){ //checking whether it's safe to place or not.
                        
                        grid[row][col]=val;
                        bool solution = SolveSudoku(grid); //getting solution.
                        if(solution){
                            return true;
                        }
                        else{ //if solution is false..then backtrack.
                            grid[row][col]=0;
                        }
                        
                    }
                }
                
                return false; //after looping from 1 to 9 for values..still we reached here then return false.
                
            }
            
        }
    }
    
    return true; //if we iterate over all the practice and came here ..then return true.
}
    
    // //Function to print grids of the Sudoku.
    // void printGrid (int grid[N][N]) 
    // {
    //     SolveSudoku(grid);
    //     for(int row = 0; row<N; row++){
    //         for(int col = 0; col<N; col++){
    //             cout<<grid[row][col]<<" ";
    //         }
    //     }
        
    // }