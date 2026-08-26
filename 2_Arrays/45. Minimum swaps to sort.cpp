


//Approach 1: Not graph approach. Just swapping and hashing used. TC-O(NLogN) SC-O(N)
// sort an array by swapping elements to correct positions
#include <bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> &arr) {
    
    // Temporary array to store elements in sorted order
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    
  	// Hashing elements with their correct positions
  	unordered_map<int, int> pos; 
    for(int i = 0; i < arr.size(); i++)
        pos[arr[i]] = i;
    
  	int swaps = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(temp[i] != arr[i]) {
            
            // Index of the element that should be at index i.
            int ind = pos[temp[i]];
            swap(arr[i], arr[ind]);
            
            // Update the indices in the hashmap
            pos[arr[i]] = i; 
            pos[arr[ind]] = ind;
            
            swaps++; 
        }
    }
    return swaps; 
}

int main() {
    vector<int> arr = {10, 19, 6, 3, 5}; 
    cout << minSwaps(arr); 
    return 0;
}