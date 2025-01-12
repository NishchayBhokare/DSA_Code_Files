//GFG question.

//There is another approroach too...with TC O(N) SC-O(N+26)
//Approach 1: TC-O(NlogN) SC-O(N)
//logic is...we are using priority queue..and map.
//map is for storing character to it's frequencies.
//and with priority queue..we are storing element frequency wise to it's character.
//max frequency character will be on top.
string rearrangeString(string str)
{
    //code here
    unordered_map<char,int> mapping;
    priority_queue<pair<int,char>>pq;

    for(auto i:str)
        mapping[i]++;
    
    for(auto i:mapping){
        pq.push({i.second, i.first});
    }
    
    string ans;
    
    while(!pq.empty() && pq.size() > 1){ //looping till not empty or size > 1. because if size equals
    //to one..there are possiblity that..solution cannot found..or can be found..because we don't have other characters
    //in which we can add top element.
        pair<int,char> p1 = pq.top(); //first pop p1 and p2..first two maximum frequency characters.
        pq.pop(); //and pop it temporarly.
        
        pair<int,char> p2 = pq.top();
        pq.pop();
        
        ans.push_back(p1.second); //get character from this p1 and p2 pair and push into the ans.
        ans.push_back(p2.second);
        
        p1.first--; //decrement frequency for that character.
        p2.first--;
        
        if(p1.first) //if still frequency greater than 0 ..add this paiar again in pq.
            pq.push(p1);
        
        if(p2.first) //same for p2. if frequency is not greater than 0 then no need to add and simply check for next top pair.
            pq.push(p2);
    }
    
    
    if(!pq.empty()){ //now..if pq not empty..that means..either top element have frequency greater than 1
    //or equal to 1.
        pair<int,char> pr = pq.top();
        
        if(pr.first > 1){ //if frequency greater than 1 that means..we can't rearrange characters. so return -1.
            return "-1";
        }
        else{
            ans.push_back(pr.second); //if frequency equals to 1..that means..we can add this character.
        }
    }
    
    return ans;
}