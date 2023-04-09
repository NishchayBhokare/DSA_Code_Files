//Example for finding Intersection(common and distinct elements) Of Two Arrays.
//on GFG

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;


//Approach 1: by sorting technique. TC-O(nlogn) SC-O(1).
 int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        int count =0,i=0,j=0;
        sort(a,a+n);
        sort(b,b+m);
        while(i < n and j < m){
            
        while((i+1) < n and a[i] == a[i+1]) i++; //applying this condition because we want common elements but it should be distinct so to avoid from duplicate common elements, applying this condition.
    
            if(a[i] < b[j]) i++;
            else if(a[i] > b[j]) j++;
            else if(a[i]==b[j]){
                count++; i++; j++;
            }
        }
        return count;
}

//Approach 2: Using Map. TC-O(N or M) SC-O(N or M)
 int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        int count = 0;
        unordered_map<int,int> mp; //creating unorderd map and for every index in array a[] assining 1 in map.
        
        for(int i=0; i<n; i++){
            mp[a[i]] = 1; //connecting every element in hasmap with 1 
        }
        
        for(int i=0; i<m; i++){ //looping over second array
            if(mp[b[i]] == 1){
                count++;
                mp[b[i]] = 0; //once increment count for current element then connect this element with 0, so that we will not increment count for this element in future.
            }
        }
        
        return count;
    }