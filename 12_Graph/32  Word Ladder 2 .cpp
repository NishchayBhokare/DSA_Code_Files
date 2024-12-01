//GFG.

//In this question we have to return all shortest transformation list which starts from starting node to end node.
//so here logic is slightly get's changed.
//we are storing vector of string in queue for every level.
//once that level finished..then remove all used string on that level.

//now for next level take last word from vector of string.
//and check by replacing characters on every index. if matched then push this new level in queue.
//also iterate till the end of this word..because we have to return all possible shortest transformation.

vector<vector<string>> findSequences(string word, string end, vector<string>& wordList) {  
    vector<vector<string>> ans;
    
    int level = 0;
    vector<string>usedLvlStr;
    unordered_set<string>s(wordList.begin(), wordList.end());
    
    queue<vector<string>>q;
    q.push({word}); //push current word in vector and push in queue.
    usedLvlStr.push_back(word); //push in used level string also.
    
    while(!q.empty()){ //loop till q not empty.
        vector<string>curr = q.front(); //get front element.
        q.pop();
        word = curr.back(); //store last word present in curr..because that will be lastly added..and we have to continue from that word.
        
        if(curr.size() > level){ //if level is increased..then this is time to erase used string of previos levels and update the level to current level.
            level++; //increment level.
            
            for(auto str:usedLvlStr){
                s.erase(str); //erase all string used in previous levels.
            }
            
            usedLvlStr.clear(); //also clear this vector.
        }
        
        
        
        if(word == end){ //if we reach till last word.
            
            if(ans.size() == 0){ //if first time we're pusing current answer in ans then push it directly.
                ans.push_back(curr);
            }
            
            else if(ans[0].size() == curr.size()){ //else for next onwards..check already present vector size from answer and compare with current..if it's same..then only insert.
                ans.push_back(curr);
            }
        }
        else{ //if word not equal to end..then just move on to next transformation of string.
            
            for(int i = 0; i<word.size(); i++){
                char original = word[i];
                    
                    for(char ch = 'a'; ch<='z'; ch++){
                        
                        word[i] = ch;
                        
                        if(s.find(word) != s.end()){ //if word found.
                            usedLvlStr.push_back(word); //then push this used word in level string
                            curr.push_back(word); //also in curr
                            
                            q.push(curr); //and push that curr in queue
                            
                            curr.pop_back(); //and pop it back..for next transformation.
                        }
                    }
                
                word[i] = original; //revert ith character to it's original state.
            }
        }
        
        
    }
    
    
    return ans; //return final answer.
}


//Approach 2: using hash map.
//same like above just used hash map.
vector<vector<string>> findSequences(string word, string end, vector<string>& wordList) {
        
    vector<vector<string>> ans;
    
    int level = 0;
    vector<string>usedLvlStr;
    unordered_map<string,bool> ump;
    
    for(auto str:wordList){
        ump[str] = true;
    }
    
    queue<vector<string>>q;
    q.push({word});
    usedLvlStr.push_back(word);
    
    while(!q.empty()){
        vector<string>curr = q.front();
        q.pop();
        word = curr.back();
        
        if(curr.size() > level){ //if level is increased..then this is time to erase used string of previos levels and update the level to current level.
            level++;
            
            for(auto str:usedLvlStr){
                ump[str] = false; //make all userd level's as false in map.
            }
            
            usedLvlStr.clear(); //also clear this vector.
        }
        
        
        
        if(word == end){ //if we reach till last word.
            
            if(ans.size() == 0){ //if first time we're pusing current answer in ans then push it directly.
                ans.push_back(curr);
            }
            
            else if(ans[0].size() == curr.size()){ //else for next onwards..check already present vector size from answer and compare with current..if it's same..then only insert.
                ans.push_back(curr);
            }
        }
        else{
            
            for(int i = 0; i<word.size(); i++){
                char original = word[i];
                    
                    for(char ch = 'a'; ch<='z'; ch++){
                        
                        word[i] = ch;
                        
                        if(ump[word] == true){
                            
                            usedLvlStr.push_back(word);
                            curr.push_back(word);
                            
                            q.push(curr);
                            
                            curr.pop_back();
                        }
                    }
                
                word[i] = original;
            }
        }
        
        
    }
    
    
    return ans;
}