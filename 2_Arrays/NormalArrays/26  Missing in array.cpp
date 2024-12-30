//GFG.
//Find Missing element in array.


//Approch 1: Most optimised Approach, using XOR. TC-O(N) SC-O(1)
//properties of xor if two number of same then there xor will be zero. 3^3=0.
int missingNumber(vector<int>& arr) {
    int n=arr.size();
    int missElem = 0;
    
    for(int i=1; i<=n+1; i++){ //take xor of 1 to n+1 elements.
        missElem = missElem ^ i;
    }
    
    for(auto i:arr){
        missElem = missElem ^ i; //then take xor for array elemetns, so at the end..only missing element will be
        //present in misselem variable.
    }
    
    return missElem;
}


//Approach 2: Using calculating totalSum of n elements then substracting it from sum of array elements.
// TC-O(N) SC-O(1) but giving TLE.
int missingNumber(vector<int>& arr) {

    int n=arr.size()+1;
    long long totalSum = (n*(n+1))/2;

    long long num=totalSum;
    
    for(auto i:arr)
        num = num-i;

    return num;
}

//Approach 3: Using set. TC-O(Nlogn) SC-O(N)
int missingNumber(vector<int>& arr) {
    int n=arr.size()+1;
    unordered_set<int>st;
    
    for(auto i:arr) //push all elements in set.
        st.insert(i);
    
    for(int i=1; i<=n; i++){     
        if(st.find(i) == st.end()) //now check..for elements from 1 to n. if elemtn is not found in set.
        //that means..elemet is not there.
            return i;
    }
}



//Approach 4: First sort vector. then check..on ith index i+1 element should be there if not..then return i+1 as missing element.
int missingNumber(vector<int>& arr) {

    int n=arr.size();
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<n; i++){
        if(arr[i] != i+1)
            return i+1;
    }
    
    return n+1; //this is the case when n+1 element i.e last element is misssing.
}