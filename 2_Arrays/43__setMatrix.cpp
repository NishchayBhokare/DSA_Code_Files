//leetcode.

//Approach 1 - Most optimised solution. TC-O(2N*M) SC-O(1)
//In this approach to remove space to store apperance of zero..we're using first row of matrix and first column.
void setZeroes(vector<vector<int>>& matrix) {
        
    int n=matrix.size(), m=matrix[0].size();

    int isFirstColZero=1; //as we have one common cell for first row and first column that is top left corner.
    //so to track whether this zero goes to first column or first row. for this we have used..

    
    for(int i=0; i<n; i++){ //loop over matrix.
        for(int j=0; j<m; j++){

            if(matrix[i][j] == 0){  //if zero found.
                matrix[i][0]=0; //mark in matrix array for row.

                if(j != 0) //to mark for column first check if j equal to zero or not. if not then mark 0 in matrix.
                    matrix[0][j]=0;
                else //else mark isFirstColZero to zero.
                    isFirstColZero = 0;
            }
        }
    }


    for(int i=n-1; i>=1; i--){ //now loop from end to i>=1 because all elements are depends on 0th row and column..so first we're 
        //setting values for other rows.
        
        for(int j=m-1; j>=1; j--){
            if (matrix[i][j] != 0) { //if element is not euqal to zero.
                if(matrix[i][0]==0 || matrix[0][j]==0){ //now check if current row is zero or col is zero then mark current cell as 0.
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(matrix[0][0] == 0){ //now check for first row.
        for(int j=0; j<m; j++){
            matrix[0][j] = 0;
        }
    }

    if(isFirstColZero == 0){ //now check for first column. As isFirstColZero is zero that means 0th column has all zeros.
        
        for(int i=0; i<n; i++){
            matrix[i][0] = 0;
        }
    }

}


//Approach 2: Used some space to store values of zero indexes.
void setZeroes(vector<vector<int>>& matrix) {
    
    int n=matrix.size(), m=matrix[0].size();

    vector<int>rowInd(n,-1); //here we're using extra space.
    vector<int>colInd(m,-1);

    //creating zeroindex ds which stores rows and column index for zero's
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if(matrix[i][j] == 0){
                rowInd[i]=0;
                colInd[j]=0;
            }
        }
    }


    for(int i=0; i<n; i++){
        
        for(int j=0; j<m; j++){

            if(rowInd[i]==0 or colInd[j]==0){
                matrix[i][j] = 0;
            }
        }
    }
}