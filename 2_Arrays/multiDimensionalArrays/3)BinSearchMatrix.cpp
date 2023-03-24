//Example to find element in matrix by binary search. 
//Leetcode
#include<iostream>
#include<vector>
using namespace std;


//TC- O(col * row) SC is constant.
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size(); //calculating size of row.
        int col = matrix[0].size(); //calculating size of column in any row.
        
        int low = 0;
        int high = (row * col - 1); //high will points to the last element.
        while(low <= high){ //looping till low less than or equal to high
            
            int mid = low + (high - low) / 2;
            
            int element = matrix[mid/col][mid%col]; //condition- 1) (mid / col) by doing this we'll get quotient which will be row index. 2) (mid % col) by doing this we will get remainder which will be column index.
                
            if(element < target) //if current element is less than target then just increment low to mid + 1.
                low = mid + 1;
            
            else if(element > target) //vice versa if smaller then, decrement high to mid - 1.
                high = mid - 1;
            
            else return true; //final condition when current element equals to target, so return true.
            
        }
        return false;  //if we reach till here that means we did'nt get element so return false.   
    }