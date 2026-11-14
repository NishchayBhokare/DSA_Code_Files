//In the XOR of all subarrays, an element only contributes if it appears an odd number of times, 
// because XORing a number an even number of times cancels it out. 

//Approach 1: Optimised approach TC-O(N) SC-O(1)
class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n = arr.size(), ans = 0; 
        
        //if n is even then answer is zero, because every element cancel itself.
        // if(n%2==0) return 0; 
        
        for(int i=0; i<n; i++){
            
            //below formula is more intuitive.
            int cnt = (i+1) + ((i+1) * (n-i-1));
            //first i+1 is state that, total number of element at left + 1 is for standing element where, current element is present.
            //second i+1 is state that, there are (i+1)elements are there which each will have (n-i-1) elements in which current element is present.
            //(n-i-1) is basically number or right elements.
            
            //one more simple way is 
            // int cnt = (i+1) * (n-i);
            
            if(cnt % 2 != 0) ans = ans ^ arr[i];
        }
        
        return ans;
    }
};


//Approach 2: TC-O(N) SC-O(1)
//Another approach: every element standing at odd position, has total even number
//of instances of itself, and even number of instances cancels each other.
//so take only element position at odd number.
class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int n = arr.size(), ans = 0; 
        
        //if n is even then answer is zero, because every element cancel itself.
        if(n%2==0) return 0; 
        
        for(int i=0; i<n; i+=2){ //every element standing on even index will have odd cnt of freq.
        //and every element present at odd pos. will have even cnt. so even cnt element cancel's each other.
        //so just consider element even pos. element which will have odd cnt.
            ans ^= arr[i];
        }
        
        return ans;
    }
};



//Appraoch 3: Brute force approach. generate all subarrays and calculate answer for it.
class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        int ans = 0, n = arr.size();
        
        for(int i=0; i<n; i++){
            
            int curr = 0;
            for(int j=i; j<n; j++){
                curr = curr ^ arr[j]; //first take answer for total number of elements present in current subarray.
                ans = ans ^ curr; //then store answer for every subarray.
            }
        }
        
        return ans;
    }
};