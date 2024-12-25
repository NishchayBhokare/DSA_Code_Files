//GFG.
// Count Square Submatrices with All Ones

//Except top row and first left column. for every index check it's neighbors. i.e left cell, up cell and diagonal up cell.
//take minimum value among all these..and update in current cell with current value + min Value from neighbor.
//basically minValue from neighbor is shows that..till that neighbor..how many number of squares are formed.
//so if we taken min value among all neighbors + current value will equals to the total number of squares formed on current index.
int countSquares(int n, int m, vector<vector<int>> &matrix) {
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            
            if(matrix[i][j] == 0) continue; //if cell is zero..then continue.
            
            int left = matrix[i][j-1];
            int up = matrix[i-1][j];
            int diagonalUp = matrix[i-1][j-1];
            
            matrix[i][j] += min({left,up,diagonalUp});
        }
    }
    
    int cnt=0; //finally count total number of squares.
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cnt += matrix[i][j];
        }
    }
    
    return cnt;
}

