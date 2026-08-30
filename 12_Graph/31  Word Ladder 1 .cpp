//GFG

//Appraoch 1: using set TC-O(N*M*26) SC-O(N).
//logic is first push first node in queue with steps value 1..then loop till queue not empty.
//pop out element from queue..and loop over length of this word..and on every index of word..check
//all 26 letters of alphabets..whether we can keep it or not. if yes then push that newly created word in queue.
//At one point..we will get target node..before queue get's empty. if queue get's empty..then return 0. that is no transformation is possible.

//also make sure, at a time..we can replace only one character from word.
//we're using unordered set here so that we can find word present in set or not in big oh 1 time.
int wordLadderLength(string start, string target, vector<string>& wordList) {
    unordered_set<string>s;
    
    for(int i = 0; i<wordList.size(); i++){ //first push all strings present in list to set.
        s.insert(wordList[i]);
    }
    
    queue<pair<string,int> >q;
    q.push({start,1});
    s.erase(start); //erase starting word from set if present so that we can not come again on startin word.
    
    while(!q.empty()){
        
        auto nodeData = q.front();
        q.pop();
        
        string word = nodeData.first;
        int seqLen = nodeData.second;
        
        if(word == target){ //if at any point popped out word i.e word equals to target word.
            return seqLen; //then return sequence length.
        }
        
        for(int i = 0; i<word.length(); i++){ //loop over the word size.
            char original = word[i]; //take it's ith original character..as this will going to change in inner for loop
            
            for(char ch = 'a'; ch<='z'; ch++){ //for ith index..check with every alphabet. 
                
                word[i] = ch;
                if(s.find(word) != s.end()){ //if the newly created word is present in set..that means..we have found one possible transformation.
                //so push this word into the queue by incrementing seqlen.

                    q.push({word, seqLen+1});
                    s.erase(word); //also erase from set..so that we will not select this word in near future.
                }
            }
            
            word[i] = original; //replace i with it's original character.
        }
        
    }
    
    
    return 0;
}



//Approach 2: we can solve this question by using unordered_map too.
//TC-O(N*M*26) SC-O(N*M).
int wordLadderLength(string start, string target, vector<string>& wordList) {
    
    unordered_map<string,bool>ump;
    
    for(int i = 0; i<wordList.size(); i++){
        ump.insert({wordList[i], true}); //pushing word list and marked as true in ump.
    }
    
    queue<pair<string,int> >q;
    q.push({start,1});
    
    if(ump[start]) //if start word is prsent then also marked as false.
        ump[start] = false;
    
    while(!q.empty()){
        
        auto nodeData = q.front();
        q.pop();
        
        
        string word = nodeData.first;
        int seqLen = nodeData.second;
        
        if(word == target){
            return seqLen;
        }
        
        for(int i = 0; i<word.length(); i++){
            char original = word[i];
            
            for(char ch = 'a'; ch<='z'; ch++){
                
                word[i] = ch;
                if(ump[word] == true){
                    
                    q.push({word, seqLen+1});
                    ump[word] = false; //removal of current word...i.e making it false.
                }
            }
            
            word[i] = original;
        }
        
    }
    
    
    return 0;
}


//Approach 3: Brute Force Approach.
class Solution {
  public:
    int wordLadder(vector<string> &words, string &s, string &e) {
      
        words.push_back(s);
        
        unordered_map<string,vector<string>>adj;
        for(int i=0; i<words.size(); i++){
            
            string wordU = words[i];
            
            for(int j=0; j<words.size(); j++){
                if(i==j) continue;
                
                string wordV = words[j];
                
                int k=0, cnt=0;
                for(int k=0; k<wordU.size(); k++){
                   
                  if(wordU[k] != wordV[k]) 
                        cnt++;
                }
                
                if(cnt == 1)
                    adj[wordU].push_back(wordV);
            }
        }
        
        words.pop_back();
        
        queue<pair<string,int>>q;
        unordered_map<string,bool>visited;
        q.push({s,1});
        visited[s]=true;
        
        while(!q.empty()){
            string word = q.front().first;
            int dist = q.front().second;
            
            q.pop();
            
            if(word == e)
                return dist;
                
            for(auto nbr:adj[word]){
                
                if(!visited[nbr]){
                    q.push({nbr,dist+1});
                    visited[nbr]=true;
                }
               
            }
        }
        
        return 0;
    }
};