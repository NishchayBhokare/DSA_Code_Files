//Leetcode easy question. 

//TC-O
class Solution {
public:
    bool checkString(string s) {
        
        bool flag = false;
        for(auto ch:s){
            if(ch=='a' and flag) return false;
            if(ch=='b') flag = true;
        }

        return true;
    }
};

class Solution {
public:
    bool checkString(string s) {
        
        return (s.find("ba") == string::npos);
    }
};