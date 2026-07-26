//Example to print matrix in spiral form.
//GFG 
#include<iostream>
#include<vector>
using namespace std;


//TC- O(col * row) SC is constant, don't consider ans vector.
vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
{
    vector<int> ans;
  int row = matrix.size(); //We can calculate row's in this way
  int col = matrix[0].size(); //for calculating columns.
  int startRow = 0, endRow = (row-1), startCol = 0, endCol = (col-1);
  int count = 0;
  while( count < (row * col)){
      
    //print starting row.
    for(int index = startCol; count < (row * col) && index <= endCol; index++){
        ans.push_back(matrix[startRow][index]);
        count++;
    }
        startRow++;
      
      //print ending column.
    for(int index = startRow; count < (row * col) && index <= endRow; index++){
        ans.push_back(matrix[index][endCol]);
        count++;
    }
      endCol--;
      
      //print ending row.
      for(int index= endCol; count < (row * col) && index >= startCol; index--){
          ans.push_back(matrix[endRow][index]);
        count++;
      }
      endRow--;
      
      //print starting column.
      for(int index = endRow; count < (row * col) && index >= startRow; index--){
          ans.push_back(matrix[index][startCol]);
        count++;
      }
      startCol++;
        
  }
  return ans;
}



//Approach 2: instead of counting, used top left var. to verify boundries.
class Solution {
public:
  vector<int> spirallyTraverse(vector<vector<int>> &mat) {
    // code here
    
    int n=mat.size()-1, m=mat[0].size()-1;
    
    int top = 0, bottom = n, left = 0, right = m;
    
    vector<int>ans;
    
    while(top <= bottom && left <= right){
        
        //print top most row.
        for(int col=left; col<=right; col++)
            ans.push_back(mat[top][col]);
            
        top++;
        
        if(top>bottom || left>right) break;
            
        //print last most column
        for(int row=top; row<=bottom; row++)
            ans.push_back(mat[row][right]);
        
        right--;
        
        if(top>bottom || left>right) break;
        
        //print bottom most row.
        for(int col=right; col>=left; col--)
            ans.push_back(mat[bottom][col]);
        
        bottom--;
        
        
        if(top>bottom || left>right) break;
            
        //print left most col.
        for(int row=bottom; row>=top; row--)
            ans.push_back(mat[row][left]);
        
        left++;
    }
    
    return ans;
  }
};