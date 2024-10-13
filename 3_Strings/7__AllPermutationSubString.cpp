 //Permutation in string leetcode.

 //Approach 1:  Analogy is first store freuency of substring character.
 //then create one window of size sub string length from given s2 string..and check..for that window..
 //freuency of character is matching or not.

//  bool checkMatch(vector<int>&subVec,vector<int>&vec){
//         for(int i = 0; i<subVec.size(); i++){ //just checking freuency is matching or not.
//             if(subVec[i] != vec[i]) return false;
//         }
//         return true;
//     }
    bool checkInclusion(string s1, string s2) {
        //if sub string is greater than parent string then no solution return false;
        if(s1.length() > s2.length()) return false;

        //creating freuecny count array for sub string.
        vector<int>subVec(26,0);
        for(int i = 0; i<s1.length();i++){
            subVec[s1[i]-'a']++;
        }

        //now we will create s1.length() size window..and will check one by one.
        vector<int>vec(26,0);
        int i = 0;
        for(; i<s1.length(); i++){
            vec[s2[i]-'a']++;
        }

        if(subVec == vec) return true;

        for(i; i<s2.length(); i++){
            vec[s2[i]-'a']++; //now incrementing count for new character which is added.
            int prevIndex = i - s1.length();
            vec[s2[prevIndex] - 'a']--;

            if(subVec == vec) return true;
        }

        return false;
    }