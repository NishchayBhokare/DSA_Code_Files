//GFG.
// We need to find the minimum substring of s1 such that s2 appears as a subsequence inside it.

// The key observation is that characters of s2 must appear in order, but they do not need to be contiguous.

// The strategy is:

// Move forward in s1 to find a place where all characters of s2 appear in order.
// Once we find such a match, we move backward to shrink the window and find the smallest substring ending at that position that still contains s2 as a subsequence.
// Update the minimum window and continue searching for the next possible window.
// This creates a forward scan to match and a backward scan to minimize the window.

// Approach
// Maintain two pointers:

// i → pointer on s1
// j → pointer on s2
// Move i forward through s1:

// If s1[i] == s2[j], increment j.
// When j == m:

// We have matched all characters of s2.
// Store end = i, which marks the end of the current valid window.

// Now move backward:

// Decrement j to stay within bounds.
// Move i backward while matching characters with s2 in reverse order.
// This finds the smallest starting index for the window ending at end.
// After backward shrinking:

// i becomes the start of the minimal valid window.
// Compute the window length: currLen = end - i + 1

// Update the minimum window if this one is smaller.

// Reset j = 0 and continue scanning forward.

// If no valid window is found, return "".

// Complexity
// Time complexity:
// O(n×m)

// Space complexity:
// O(1)



//Approach 1: optimized approach.
class Solution {
  public:
  //TC-O(N*M)
    string minWindow(string& s1, string& s2) {
        // Code here
        
        int ind1=0, ind2=0, minLen=INT_MAX,start=-1;
        
        while(ind1<s1.size()){
            
            if(s1[ind1] == s2[ind2]){ //first compare bitween both string
                ind2++; //if character is same then increment ind2, ind1 will get automatic increment 
                //at the end of flow.
            }
            
            if(ind2 == s2.size()){ //if ind2 is equal to target string that means, we have process all the characters.
                
                ind2--; //bring ind2 in array range.
                int end = ind1; //end of the current window will be the ind1 in s1 string
             
                
                while(ind2>=0){ //now performing reverse engineering, 
                //here we will get shortest string from string which we already found.
                //checking has to be done by back.
                    
                    if(s1[ind1] == s2[ind2]){ //if character is match. 
                        ind2--; //decrement s2 string counter
                    }
                    ind1--; //same for s1 in both case, wheter it's match or not.
                }
                
                ind1++; //bringe ind1 in range.
                 
                int currLen = end - ind1 + 1; //check current length of window.
                
                if(currLen < minLen){ //update minLen if currentlen lesser than it.
                    start = ind1;
                    minLen = currLen;
                }
                ind2=0; //initialize ind2 as 0 for next iteration.
            }
            
            ind1++; //increment first counter
               
        }
        
        if(start==-1) return "";
        
        return s1.substr(start,minLen);
    }
};
