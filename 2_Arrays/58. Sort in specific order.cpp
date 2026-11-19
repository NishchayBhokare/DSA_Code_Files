
//Approach 1: Optmised Appraoch TC-O(Nlogn) SC-O(1)
//The idea is to utilize the fact that negative odd numbers will be treated as smaller in ascending sort. 
// Convert all odd elements to negative, making larger odd values more negative 
// (e.g., 7 becomes -7). 

class Solution {
  public:
    void sortIt(vector<int>& arr) {

        int n = arr.size();
        
        for(int i=0; i<n; i++){
            
            if(arr[i]%2 == 1) arr[i]*=-1;
        }
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n; i++){
            
            if(arr[i]<0) arr[i]*=-1;
            else break;
        }
    }
};)

//Approach 2: Optimised Approach   TC-O(Nlogn) SC-O(1) 
class Solution {
  public:
    void sortIt(vector<int>& arr) {

        int n = arr.size();
        
        int i=0,j=n-1;
        
        while(i<=j){
            
            if(arr[i]%2 == 1) i++;
        
            else if(arr[j]%2 == 0) j--;
            
            else 
                swap(arr[i++],arr[j--]);   
        }

        sort(arr.begin(),arr.begin()+j+1, greater<int>());
        sort(arr.begin()+i,arr.end());
    }
};



//Approach 3 : Brute force approach TC-O(Nlogn) SC-O(N) 
// Function to sort array as per the condition
void sortIt(vector<int>& arr) {

    vector<int> odds;  
    vector<int> evens; 

    // Separate the elements into odds and evens
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 1) {
            odds.push_back(arr[i]);
        } 
        else {
            evens.push_back(arr[i]);
        }
    }

    // Sort odds in descending order
    sort(odds.begin(), odds.end(), greater<int>());

    // Sort evens in ascending order
    sort(evens.begin(), evens.end());

    // Merge both back into the original array
    int idx = 0;

    for (int i = 0; i < odds.size(); i++) {
        arr[idx++] = odds[i];
    }

    for (int i = 0; i < evens.size(); i++) {
        arr[idx++] = evens[i];
    }
}