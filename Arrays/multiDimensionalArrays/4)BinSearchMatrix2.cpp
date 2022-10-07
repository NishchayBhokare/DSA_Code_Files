//Example to find element in matrix by binary search. (row wise and column wise sorted elements)
#include<iostream>
#include<vector>
using namespace std;

//TC- O(col * row) SC is constant.
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        int rowIndex = 0;
        int colIndex = (col-1); //starting from last element of first row. i.e last column of first row.
        while(rowIndex < row && colIndex >=0){ //looping till rowindex is less than row and column index greater than or equal to 0.
            int element = matrix[rowIndex][colIndex]; //storing current element in element.
            if(element < target) //if element is less than target, then search in next row. cause there is no chance of target element in current row.
                rowIndex++; //increment rowindex.
            
            else if(element > target) //if element is greater than target, then decrement column, cause either target element will present in current row or target element won't present in matrix.
                colIndex--;
            
            else return true; //condition when element is found so return true.
        }
        
        return false; //return false.
    }