//Example to print two dimensinal matrix in wavy form. 
//Coding ninja
#include<iostream>
#include<vector>
using namespace std;

//TC- O(col * row) SC is constant, don't consider ans vector.
//Analogy:-
    //When column index is even then we are iterating from top to bottom and for odd, bottom to top.
vector<int> wavePrint(vector<vector<int>> arr, int row, int col)
{
    
    vector<int> ans;
    for(int j=0;j<col; j++)
    {
        
        if( j & 1){
            //for odd no. of col i.e j, iterate bottom to top
            for(int i=(row-1);i>=0; i--){
                ans.push_back(arr[i][j]);
            }
        }
        else{
            //for even, iterate top to bottom
            for(int i=0; i<row; i++){
                ans.push_back(arr[i][j]);
            }
        }  
    }
    return ans;
    
}