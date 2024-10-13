//Leetcode

//Approach 1: Best solution. TC-O(N) SC-O(1)
int compress(vector<char>& chars) {
        int i =0,ansInd = 0, n=chars.size(); //without using extra..instead using answer index
        //which points to index on which we will add character and its count.

        while(i<n){
                int j = i+1;
                while(j<n && chars[i] == chars[j]) j++; //loop till i == j.
                int count = j-i; 
                chars[ansInd++] = chars[i]; //add character on index and increment index to store it's count if count> 1;.
                if(count > 1){
                    string temp = to_string(count); //convert count into tostring.
                    for(auto ch:temp) chars[ansInd++] = ch; //loop over string to store count character seperately as count > 9 then store seperately.
                }
            i=j; //now j will point to new or different element so point i to j.
        }
        
        return ansInd; //retur answer index. which is also shows size of chars array.
}

//Approach 2: TC-O(N) SC-O(N)
class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size() == 1) return 1;
        int n = chars.size();
        string ans=""; //using extra space.
        int i=0; 
            while(i<chars.size()){
                int j = i+1;
                while(j<n && chars[i] == chars[j]) j++;
                int count = j-i;
                ans+= chars[i];
                if(count > 1){
                    string temp = to_string(count);
                    for(auto ch:temp) ans+= ch;
                }
                i=j;
            }

            for(int i = 0; i<ans.length(); i++) chars[i] = ans[i];

            return (ans.length());
        }
    
 
};