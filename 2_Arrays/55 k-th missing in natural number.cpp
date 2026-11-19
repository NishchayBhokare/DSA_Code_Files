//GFG.
//Approach 1: Most optimised. TC-O(Nlogn) SC-O(1)
class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        
        // Sort the removed numbers in ascending order.
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<arr.size(); i++){
            
            // If arr[i] is within the range of our current kth missing number,
            // skip this removed number by incrementing k.
            if(arr[i] <= k) k++;
        }
        // Return the adjusted kth missing positive integer.
        return k;
    }
};



//Approach 2: TC-O(Nlogn + K) SC-O(1) 
class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
     
        sort(arr.begin(), arr.end());
        
        int ind=0, num=1;
        while(k>0){
            
            if(ind<arr.size() and arr[ind] == num) ind++;
            
            else k--;
            
            num++;
        }
        
        return (num-1);
    }
};

//Approach 3: Naive approach TC-O(K+N) SC-O(N)
class Solution {
  public:
    int findKthSmall(vector<int>& arr, int k) {
        // code here
        unordered_set<int>st;
        
        for(auto num:arr) st.insert(num);
        
        int i=1;
        while(k>0){
            
            if(st.find(i) == st.end()) k--;
            i++;
        }
        
        return i-1;
    }
};
