
//The question could solve using trie. that approach is optimised one.

//Approach: Using DFS, with bfs it's not possible becuase on every index we could have multiple possible states
//and to treat that problem individually we can't handle it using dfs.


class Solution {
  public:
    bool dfs(int row, int col, string &word, int ind, vector<vector<int>>&visited, vector<string>&ans, vector<vector<char>>& board){
        
        int n = board.size(), m=board[0].size();
        
        if(ind==word.size()){
            ans.push_back(word); //if possible then insert word into answer vector.
            return true;
        }
        
        for(int dirR=-1; dirR<=1; dirR++){
            for(int dirC=-1; dirC<=1; dirC++){
                
                int newR=row+dirR, newC=col+dirC;
                
                if(newR>=0 and newR<n and newC>=0 and newC<m and !visited[newR][newC] and board[newR][newC]==word[ind]){
                    
                    visited[newR][newC]=1;
                    bool isTrue = dfs(newR,newC,word,ind+1,visited,ans,board);
                    visited[newR][newC]=0; //backtrack.
                    
                    if(isTrue) return isTrue;
                    
                }
            }
        }
        
        return false;
    }
  
  
    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
       
        vector<string>ans;
        int n = board.size(), m=board[0].size();
        
        for(int i=0; i<dictionary.size(); i++){
            
            string word = dictionary[i];
            
            char firstChar = word[0];
            bool isPresent = false;
            
            for(int j=0; j<n; j++){
                for(int k=0; k<m; k++){
                    
                    vector<vector<int>>visited(n,vector<int>(m,0));
                    
                    if(board[j][k] == firstChar){
                        //here check is word present in matrix or not.
                        if(dfs(j,k,word,1,visited,ans,board)){
                            isPresent = true;
                            break;
                        }
                        
                    }  
                }
                
                if(isPresent) break;
            }
        }
        
        return ans;
    }
};

