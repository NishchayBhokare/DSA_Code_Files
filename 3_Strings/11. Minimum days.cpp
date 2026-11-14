
//Approach 1: Most optimised approach. TC-O(N) SC-O(1)
// The idea is to count the number of adjacent equal pairs and update this count whenever a character is replaced. 

// Since only the pairs involving the replaced position can change, we only need to check its left and right neighbors.

// C++: Strings are mutable, so we can directly replace a character in O(1) time without using extra space.
// Java, Python, C# and JavaScript: Strings are immutable, so we convert the string into a mutable 
// character array/list once and perform replacements in O(1) time per operation. This requires O(n) 
// extra space.
int getMinimumDays(string &s, vector<int> &p) {
    // code here
    
    int cnt = 0;
    
    for(int i=0; i<s.size()-1; i++){
        
        if(s[i] == s[i+1]) cnt++;
    }
    
    if(cnt == 0) return 0;
    
    for(int i=0; i<p.size(); i++){
        
        int pos = p[i];
        

        if(pos != 0 and s[pos-1] == s[pos]) 
            cnt--;
        
        
        if(pos != p.size()-1 and s[pos] == s[pos+1])
            cnt--;
        
        
        s[pos] = '?';
        
        if(cnt == 0) 
            return i+1;
    }
    
    return 0;
}




//Approach 2: Optimised approach. TC-O(N) SC-O(N)
// The idea is to store all adjacent equal pairs in a hash set and remove a pair when one of its 
// characters is replaced by ?.

// This avoids scanning the complete string after every day.
int getMinimumDays(string &s, vector<int> &p) {

    unordered_set<int>st;

    for(int i=0; i<s.size()-1; i++){
        
        if(s[i] == s[i+1]){ //if char at i and i+1 is same then insert ith pos. in set.
            st.insert(i); 
        }
    }
    
    if(st.size() == 0) return 0;
    
    for(int i=0; s.size()-1; i++){
        
        int pos = p[i]; //take every pos. from permutation array.
        
        if(pos != 0) //handle pos as 0 case, because for pos = 0  there no pos - 1.
            st.erase(pos-1); //why we're deleting pos-1, because in set, for each equal pair we're 
            // storing only left part of pair not right part. and suppose, if that left pos - 1 is also
            //equal to left pos char, then we have to delete both right.
            //eg. b c a a a d e -> in this example you can see for the pair 3 and 4, left pos is 3 and this will be in set. but ther is pos 2 which equals to 3 and if we replace 3 pos char. then 2 pos char will not be part of adjacent char. so remove it too.
            //    0 1 2 3 4 5 6 

        st.erase(pos); //remove current pos.
        
        if(st.size() == 0) { 
            return i+1; //return i+1th day as answer.
        };
    }
    
    return -1; //code will not reach here. it's just for there to return.
}