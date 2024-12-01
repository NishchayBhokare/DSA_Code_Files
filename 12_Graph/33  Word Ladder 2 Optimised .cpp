//GFG , leetcode.

//More optimised approach than ladder 2. 32th problem.
//1) first do normal word ladder 1 approach and create shrotest path with maintaining its level and store it into the map.
//2) second backtrack from last word to start word..with the help of this map
//why from last word? 
//beacuse if we backtrack from last word..then there will be few paths which are shortest path to reach the end word right.
//so because we backtacking from last word..we will backtack only for possible path by checking is this new word is with right level or not.
//that's why we stored words with level in map.

class Solution {
    unordered_map<string,int>ump;
    vector<vector<string>> ans;
    vector<string>seq;
    string beginWord;
    
public:

    void solve(string end){
        
        if(end == beginWord){ //if reached till last then reverse seq and store it in answer..as we backtracking from last..then sequence need to get reverse.
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end()); //again reverse to make it in original condition.
            return;
        }
        
        int level = ump[end]; //get level of this current word.
        
        
        for(int i = 0; i<end.size(); i++){ //and check..from this word..possible word which can createa and will have level is level-1.
            char original = end[i];
            for(char ch = 'a'; ch<='z'; ch++){
                
                end[i] =  ch;
                if(ump[end] == level-1){ //check for level-1 because we're doing backtrack..so previous level should of current level-1 
                    
                    seq.push_back(end); //push this end word in seq. 
                    solve(end);
                    seq.pop_back(); //after dfs call over pop back. for next transformation of checking.
                }
            }
            
            end[i] = original; //revert ith character to it's original value.
        }
    }


    vector<vector<string>> findSequences(string word, string end, vector<string>& wordList) {
        
//1) first do norma word ladder 1 approach just create map by maintainig level for each word.
        unordered_set<string>s(wordList.begin(), wordList.end());
        beginWord = word;
        
        queue<string> q;
        q.push({word}); //store initial node..i.e first node in queue
        s.erase(word);
        ump[word] = 1; //current level is first. so store this level for first starting word.
        
        while(!q.empty()){
            word = q.front();
            q.pop();
            
            int level = ump[word];
            
            if(word == end) //if reached to last word.then break.
                break;
            
            for(int i = 0; i<word.length(); i++){
                char original = word[i];
                
                for(char ch = 'a'; ch<='z'; ch++){
                    word[i] = ch;
                    
                    if(s.count(word)){ //it will return 1 if present else 0.
                        q.push(word);
                        s.erase(word);
                        
                        ump[word] = level+1; //if new word is found..then increase it's level by current level plus 1.
                    }
                }
                
                word[i] = original;
            }
        }
        

    //2) 2nd step is backtrack from last word to starting word.
        if(ump[end]){ //first check..whether we able to find shortest path or not..so check..end word prsent in map or not..if not then return simple empty ans.
            seq.push_back(end); //push this end word in sequence vector.
            
            solve(end); //call for function.
        }
      
        return ans;
    }

};