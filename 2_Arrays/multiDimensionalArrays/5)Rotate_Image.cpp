//1: TC-O(N) SC-O(1) -> logic is first take transpose of matrix.
//then just reverse rows.

// void reverseEveryRow(int row,vector<vector<int>>& matrix){
//     int startCol = 0, endCol = matrix.size()-1;
//     while(startCol < endCol){
//         swap(matrix[row][startCol++], matrix[row][endCol--]);
//     }
// }
    void rotate(vector<vector<int>>& matrix) { 
        for(int row =0; row<matrix.size(); row++){
            for(int col = 0; col<matrix.size(); col++){
                if(row < col){ //if row less thn col..don't swp.
                    swap(matrix[row][col], matrix[col][row]);
                } //one more method we can do is...by doing int col = row+1. due to which
                //only those elements gets swpeed which need to be swap.
            }
        }

        //now reverse every row.
        for(int row = 0; row<matrix.size(); row++){
            //reversing every row.
            int startCol = 0, endCol = matrix.size()-1;
            while(startCol < endCol){
                swap(matrix[row][startCol++], matrix[row][endCol--]);
            }
        }
   
    }

//2: TC-O(N) SC-O(N)
void rotate(vector<vector<int>>& matrix) {
        int rowSize = matrix.size(), colSize = matrix[0].size();
        vector<vector<int>>vec(rowSize, vector<int>(colSize,0));

        for(int i = 0, col=0; i<rowSize && col<colSize; i++,col++){
            for(int j = 0, row=rowSize-1; j<colSize && row>=0; row--,j++){ 
                vec[i][j]=matrix[row][col];
                
            }
        }
        matrix = vec;
    }