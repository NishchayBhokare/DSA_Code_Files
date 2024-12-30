//Remove duplicate elements
//GFG

//Optimised approach new question in gfg.
//update the array as distinct elemnts and return size of distinct elemnt.
int remove_duplicate(vector<int> &arr) {
        if(arr.size() == 1) return 1;
       int i = 0;
       int j = 1;
       int n = arr.size();
       while(j < n){
           if(arr[i] == arr[j]) j++; //if i and j eleemnt are same...then increment j.
           else{ //else store jth element in i+1st index. then increment both.
               arr[i+1] = arr[j];
               i++;
               j++;
           }
       }
       return (i+1);
    }

//Approach 1: Using set and vector. TC-O(n) SC -O(No. of duplicate element)
 vector<int> removeDuplicate(int A[], int N) {
       unordered_set<int> s; //we are using hashing here.
       vector<int> v;
       for(int i=0;i<N;i++){ //Iterating over the array.
          if(s.find(A[i])==s.end()){ 
        // checking whether current element is already present in hash table or not. if not then put it in
        // hashtable and also in vector.
              s.insert(A[i]);
              v.push_back(A[i]);
          }
       }
       return v;
   }

//Approach 2: Using map. TC-O(n) SC -O(No. of duplicate element)
 vector<int> removeDuplicate(int arr[], int N) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0; i<N; i++){
           if(mp.find(arr[i]) == mp.end()){
               ans.push_back(arr[i]);
              mp[arr[i]]++;
           }
        }   
       return ans;
}

//Approach 3: Using map  TC-O(n) SC -O(No. of duplicate element)
 vector<int> removeDuplicate(int arr[], int N) {
       unordered_map <int,int> mp;
       vector<int> ans;
       for(int i=0; i<N; i++){
           mp[arr[i]]++;
       }
       for(int i=0; i<N; i++){
           if(mp[arr[i]] != 0){
               ans.push_back(arr[i]);
               mp[arr[i]] = 0;
           }
       }
       
       return ans;
    }    


//Approach 4: TC-O(NLogN) SC-O(No. of distinct elemtns)
int removeDuplicates(vector<int> &arr) {
        
    int n=arr.size();
    set<int>st;
    
    for(auto i:arr){
        st.insert(i);
    }
    
    int i=0;
    for(auto j:st){
        arr[i++]=j;
    }
    
    return i;
}

