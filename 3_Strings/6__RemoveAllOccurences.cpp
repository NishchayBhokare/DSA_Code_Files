

//Approach1: first we are chcking after erasing sub part is length of string
//greater than zero or not. and when we are finding par
string removeOccurrences(string s, string part) {
      while(s.length()>0 && s.find(part) < s.length()){ //s.find returns starting index of substring which need to be find.
        //s.erase have starting index and number of parts need to deleted, if value return by part is greater length...then no need to check further because no subpart is present.
       s.erase(s.find(part),part.length()); //find will return starting index of
       //subpart character...so we're erasing from starting index,to length of part.
      }
        return s; 
    }


//Approach 2: TC-O(N*M) size of s and size of substring.
//logic is if first charcter is not same with part' first character then no need to check further
//for sub part starting from this first character so move on.
//if first character is same. then possibility of solution.
//so issub is true. then check for remainig part of sub string. if it not same.
//then is sub is false and break from loop.
//now checking if whole is travrsed then is sub will be true..so erase this new subpart from s string.
//i represent to starting index. now again assign i to 0 because now we need to check again as we erased.
//if we by chance breaked from for loop then move on to next element.
string removeOccurrences(string s, string part) {
       int i = 0;
        while (i < s.size()) {
            if (s[i] == part[0]) {
                bool isSub = true;
                for (int j = 0; j < part.size(); j++) {
                    if (s[i + j] != part[j]) {
                        isSub = false;
                        break;
                    }
                }
                if (isSub) {
                    s.erase(i, part.length());
                    i = 0;
                } else {
                    i++;
                }
            } else {
                i++;
            }
        }
        return s;
    }

//Approach 3:
//first taking length of substring part.
//then in loop..creating substring from i to length of part.
string removeOccurrences(string s, string part) {
      
        int subLen = part.length();
        string sub;
        int i = 0, j = subLen-1;
        while(j<s.length()){
            sub = s.substr(i,subLen);
            if(sub == part){ //if sub string same to part.
                s.erase(i,subLen); //then erase substring from s.
                i=0; j=subLen-1; //now again assign i to 0 and j to end of leftmost substring.
            }
            else{
                i++; j++;  //if not same..then increment both.
            }
        }
        return s;
    }
