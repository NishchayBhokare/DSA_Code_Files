//GFG problem

//Approach 1: we can do little optimization of checking is safe functino...if we 
//use map..then we can reduce little complexity..still tc will be O(N!) SC-O(N2);
unordered_map<int,int>rowMap; //little optimised approach using map.
unordered_map<int,int>upparDiagonal;
unordered_map<int,int>lowerDiagonal;

bool isPossible(vector<vector<int>> &board, int row, int col){
    int n = board.size();
    
        // checking this:  -------- , checking for row from current index to left.
    if(rowMap[row]){
        return false;
    }
    
    // \
    //  \
    //   \
    //upper diagonal
    
    if(upparDiagonal[n-1+col-row])
        return false;
    
    
    //lower diagonal
    //    /
    //   /
    //  / 
    if(lowerDiagonal[row+col])
        return false;

    return true;
}

void updateBoard(vector<vector<int>> &board,int row, int col, int val){
    int n = board.size();
    
    //update board
    board[row][col] = val;
    
    //update row
    rowMap[row] = val;
    
    //update upper diagonal 
    upparDiagonal[n-1+col-row] = val; //this is expression to make..all diagonal value same fo or upper diagonal.
    
    //update lower diagonal
    lowerDiagonal[row+col] = val; //same for lower diagonal.
    
}


void solve(vector<vector<int>> &board, int col, 
    vector<int>&temp, vector<vector<int>> &ans,  int n){
    
    if(col == n){
        ans.push_back(temp);
        return;
    }
    
    
    for(int row = 0; row<n && col<n; row++){
        
        if(isPossible(board,row,col)){
            temp.push_back(row+1);
            
            updateBoard(board,row,col,1); //udpate board.
            
            solve(board,col+1,temp,ans,n);
            
            updateBoard(board,row,col,0); //backtrack.
            
            temp.pop_back();
        }
    }
}

vector<vector<int>> nQueen(int n) {
    
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    
    vector<int> temp;

    int col = 0;
    
    solve(board,col,temp,ans,n);
    
    return ans;
}



//Approach 2: TC-O(N!) SC-O(n2)
bool isSfe(vector<vector<int>> &board, int row, int col){
    int n = board.size();
    //while looping for below three loops..if at any time..board's ith and jth value is 1..then return false.
    //else at the end return true. that is safe.

        // checking this:  --------curr , checking for row from current index to left.
    int newCol = col;
    for(; newCol>=0; newCol--){
            if(board[row][newCol] == 1) //if already one preesent that means..can't place
            return false;
    }
    
    // \
    //  \
    //   \curr
    //upper diagonal
    int newRow = row;
    newCol = col;
    for(; newRow >=0 && newCol>=0; newRow--,newCol--){
        if(board[newRow][newCol] == 1) //if already one preesent that means..can't place
            return false;
    }
    
    //lower diagonal
    //    /curr
    //   /
    //  / 
    newRow = row;
    newCol = col;
    for(; newRow<n && newCol >=0; newRow++,newCol--){
            if(board[newRow][newCol] == 1) //if already one preesent that means..can't place
            return false;
    }

    return true;
}


void solve(vector<vector<int>> &board, int col, 
    vector<int>&temp, vector<vector<int>> &ans,  int n){
    
    if(col == n){ //if columns is out of range..then store temp in ans.
        ans.push_back(temp);
        return;
    }
    
    
    for(int row = 0; row<n && col<n; row++){ //loop every row and particular column.
        
        if(isSfe(board,row,col)){ //check is safe.
            temp.push_back(row+1); //then push..row+1..because we want answer in that way.
            
            board[row][col] = 1; //setting value as 1..that we have placed q on this index.
            
            solve(board,col+1,temp,ans,n);
            
            board[row][col] = 0; //backtrack.
            
            temp.pop_back(); //backtrack..pop back..whatever value u have pushed.
        }
    }
}

vector<vector<int>> nQueen(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0)); //creating board and initialising with 0.
    
    vector<int> temp; //creating temp vector to store answer for one path.

    int col = 0; //initially checking for first column.
    
    solve(board,col,temp,ans,n);
    
    return ans;
}