//Leetcode.
//In this question we have to check particular word is present in matrix or not. word should be in sequential manner
//horizontally or vertically.

//Approach 1: My clean approach.TC-O(N*M*4^wordLen) SC-O(wordLen)
bool isMatchingChar(int newRow, int newCol, int strInd, vector<vector<char>>& board, string &word){

    int n = board.size(), m=board[0].size();

    if((newRow>=0 && newRow<n) && (newCol>=0 && newCol<m) && (board[newRow][newCol] == word[strInd]) )
        return true;
    
    return false;
}

bool searchWord(int row, int col, int strInd, vector<vector<char>>& board, string &word, int &strLen){

    if(strInd == strLen) return true; //if process all the string characters then return true.

    vector<int>rowArr = {-1,1,0,0}; //create arrays to move in four direction for current character.
    vector<int>colArr = {0,0,-1,1};

    for(int i=0; i<4; i++){

        int newRow = rowArr[i] + row;
        int newCol = colArr[i] + col;

        if(isMatchingChar(newRow, newCol, strInd, board, word)){ //if it's matching character and safe to move.

            char ch = board[row][col]; //Also, we can't select particular row's character multiple times.
            board[row][col]='-1'; //so make it as char -1. so that it won't match with any alphabet.

            if(searchWord(newRow, newCol, strInd+1, board, word, strLen)) //now search for next character.
                return true; //if we get true then return true. no need to check further.
            
            board[row][col]=ch; //if not..then before going back. revert this changes. i.e backtrack.
        }
    }

    return false; //even after checking in all four directions and we not found solutin then return false.
}

bool isWordExist(vector<vector<char>>& board, string word) {
    int n = board.size(), m=board[0].size();
    int strLen = word.length();

    for(int row=0; row<n; row++){

        for(int col=0; col<m; col++){

            if(board[row][col] == word[0]){ //finding first character.

                int strInd=1; //as we found first character so check for rest of characters.
                if(searchWord(row, col, strInd, board, word, strLen))
                    return true;
            }
        }
    }

    return false;
}


//Approach 2: Using recursion call in all four directions.
bool isMatchingChar(int newRow, int newCol, int strInd, vector<vector<char>>& board, string &word){

    int n = board.size(), m=board[0].size();

    if((newRow>=0 && newRow<n) && (newCol>=0 && newCol<m) && (board[newRow][newCol] == word[strInd]) )
        return true;
    
    return false;
}

bool searchWord(int row, int col, int strInd, vector<vector<char>>& board, string &word, int &strLen){

    if(strInd == strLen) return true;
    
    if(isMatchingChar(row, col, strInd, board, word) == false) //is matching fails then return false.
        return false;

    //else continue to check for next set of characters.
    
    char ch = board[row][col]; //we don't want to select particular row's character multiple times.
    board[row][col]= '*'; //so make it as char -1. so that it won't match with any alphabet.

    bool up = searchWord(row-1, col, strInd+1, board, word, strLen); //call in all four directions and check.
    bool left = searchWord(row, col-1, strInd+1, board, word, strLen);
    bool right = searchWord(row, col+1, strInd+1, board, word, strLen);
    bool down = searchWord(row+1, col, strInd+1, board, word, strLen);
    
    board[row][col]=ch; //before going back. revert this changes. i.e backtrack.
        
    
    if(up || left || right || down)
        return true;
    
    return false;   
}

bool isWordExist(vector<vector<char>>& board, string word) {
    int n = board.size(), m=board[0].size();
    int strLen = word.length();

    for(int row=0; row<n; row++){

        for(int col=0; col<m; col++){

            if(board[row][col] == word[0]){ //finding first character.

                int strInd=0; //in this approach we have to start from 0th index. because at entry point only
                //we're checking current character is matching or not.
                if(searchWord(row, col, strInd, board, word, strLen))
                    return true;
            }
        }
    }

    return false;
}