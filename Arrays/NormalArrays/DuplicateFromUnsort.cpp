// Example for finding duplicate elements and return it.
// link-
    // https://practice.geeksforgeeks.org/problems/remove-duplicates-from-unsorted-array4141/1#

   class Solution{
    public:
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
}; 