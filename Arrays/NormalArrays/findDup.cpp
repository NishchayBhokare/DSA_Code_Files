// Example for finding duplicate elements and return it.
// link-
    // https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1#

#include<bits/stdc++.h>
using namespace std;

   //optimised approach to solve problem
    vector<int> duplicates(int arr[], int n) {  
        //Time complexity is O(n) i.e =n+n=n
      // space complexity is O(n);
        vector <int> v; //creating main vector which we will return.
        vector <int> v2(n); //creating temporary vector of size n & by default all elements will initialized with 0.
        int i=0;
        while(i<n){ 
            v2[arr[i]]++; //for eg. arr[i]=5. then here we are incrementing v2[5] by 1.
            i++;
        }
        
        for(int j=0;j<v2.size();j++){
            if(v2[j] > 1){ //if element at jth index is greater than 1, (that mean particular element is duplicate)
            v.push_back(j);// then we will push that j (which showing element) into vector v. 
            }
        }
        
        if(v.size()==0){ // handling case when there is no duplicate element
            v.push_back(-1); //we not any duplicate element then we will push -1.
        }
        return v; //returning vector which only contain duplicate elements.
    }

//my first approach.
vector<int> duplicates(int arr[], int n) //Time complexity is O(n.logn) i.e = n+n.logn=n.logn
{ 
    vector<int> v;
    int p = 0, q = 1;   // initializing p & q.
    sort(arr, arr + n); // here we are performing sort over the normal array. sort(initial address , end address)
    while (p < n - 1)
    { // we will loop till the n-1 cause last element will always unique. and also if size (n) is 1 or 0 it will not enter in loop so it will return -1.

        if (arr[p] != arr[q])
        { // if not same then move on
            p++;
            q++;
        }
        else
        {
            if (!binary_search(v.begin(), v.end(), arr[p]))
            { // if same then first check whether element is present in vector or not, if not then only push otherwise skip. and move on.
                v.push_back(arr[p]);
            }
            p++;
            q = p + 1;
        }
    }
    if (v.size() == 0)
    { // if no duplicate element is found then return -1 and also it will execute when size is 1 or 0.
        v.push_back(-1);
    }
    return v;
}

// Below method is More Optimized then above solution
vector<int> duplicates(int arr[], int n) {
        vector <int> v;
        int p=0,q=1;
        sort(arr,arr+n); 
        while(p<n-1){
                if(arr[p]==arr[q]) //if same then enter in if block. and if not same then move on.
                {
                    if(!binary_search(v.begin(),v.end(),arr[p])){
                    v.push_back(arr[p]);
                    }
                }
                p++;
                q=p+1;
        }
        if(v.size()==0){
            v.push_back(-1);
        }
        return v;
    }