//Remove duplicate elements
//GFG

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




