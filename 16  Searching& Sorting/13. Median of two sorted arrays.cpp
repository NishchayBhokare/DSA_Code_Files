//Using binary Search. //GFG.

//Approach 1: Most optimised Approach. TC-O(min(Logn, Logm)) SC-O(1).
//first we're choosing minimum size array. if a is not minimum then swap it with b.

//now, as we know. mid element will be on n1+n2/2. so to get this element.
//we will do binary search on array A.
//while doing BS, we're taking mid1 elements from Array A. and (mid2 = requiredLeftPart-mid1) elements from Array b.
//now mid1 and mid2 will points to starting position of right part in both the arrays.
            M1                                         M1
eg. 1 2 3 | 4 5 (for n=(n1+n2) of even case)    eg. 1 3 | 4 (for n = (n1+n2) of odd case)
        2 | 7 8                                       2 | 7
            M2                                          M2  
//Answer for even will be. max(2,3)+min(4,7)/2.0 and for odd min(3,2).

//for Mid1, L1 is Mid1-1 and R1 is Mid1 itself. same for mid2.
//now what will be the median condition. for two merge sorted array.
//if L1 & L2 is lesser than R2 & R1 then this is valid median. (only one median will be valid so return answer)
//if n is even case then take max from left side + min from right side and divide by 2. and for n is odd take max from left side.
//if L1 > R2 that means we need minimum element in left part of Array A, so do high=mid-1.
//if L2 > R1 that means we need maximum element in right part of Array A, so do low=mid+1.

double medianOf2(vector<int>& a, vector<int>& b) {
    
    //we will process over smallest array size.
    if(b.size() < a.size())
        return medianOf2(b,a);
        

    int n1=a.size(), n2=b.size();
    int n=n1+n2;
    int left = (n+1)/2; //plus one to handle odd case. 
    
    int low=0, high=n1;
    
    while(low <= high){
        
        int mid1 = low+(high-low)/2;
        int mid2 = left - mid1;
        
        int L1=INT_MIN, L2=INT_MIN; //initially point Left L1,L2 to as min as possible.
        int R1=INT_MAX, R2=INT_MAX; //for right as max as possible.
        
        if(mid1 > 0) L1=a[mid1 - 1]; //if mid1 greater than 0 then only we can update L1.
        if(mid2 > 0) L2=b[mid2 - 1]; //same for mid2 and L2.
        
        if(mid1 < n1) R1=a[mid1]; //if mid1 is lesser than n1 then only we can update R1.
        if(mid2 < n2) R2=b[mid2]; //same for mid2 & R2.
        
        
        if(L1 <= R2 && L2 <= R1){ //if we found right combination then return answer.
            
            if(n%2 == 0) //even numebr of case. total elements.   
                return (max(L1,L2) + min(R1,R2))/2.0;
            
            else //odd number of case.  
                return max(L1,L2);
        }
        
        else if(L1 > R2) //need lesser element in left part from array A.
            high = mid1 - 1;
        
        else
            low = mid1 + 1; //need greater elemeent in right part from array A.
        
    }
    
    
    return 0; //this will never run.    
}



//Approach 2: Optimised TC-O(N+M) SC-O(1).
//As we can't use merged array. but we know. mid element will be n1+n2.
//so we're using one cnt varaible which tells, on which element number we're. if it's n1+n2 then 
//update mid element. i.e val1 and val2.
double medianOf2(vector<int>& a, vector<int>& b) {
    vector<int>merged;
    
    int n1=a.size(), n2=b.size(), n=n1+n2;
    int i=0, j=0, cnt=0; //cnt varaible.
    
    int ind2 = n/2, ind1 = n/2 - 1, val1=INT_MAX, val2=INT_MAX;
    //we're taking ind1 also. because for even case we have to take addition of two numbers and then division.
    //for odd case we will neglect ind1 and solely focus on ind2.
    
    //Approach is similar like merge two sorted but here we just hypothetically merging two arrays.
    while(i<n1 && j<n2){
        
        if(a[i]<b[j]){ //if ith element is lesser than jth eleemnt then increment count as we going to process ith eleemnt.
            
            if(cnt == ind1) val1 = a[i]; //before that check current count is equals to ind1 or ind2. because there are the mid elements for us
            //if it's equal the store there vlaue in val1.
            
            if(cnt == ind2) val2 = a[i];
            
            i++; cnt++; //increment both.
        }
        else{
            
            if(cnt == ind1) val1 = b[j]; //same for else case.
            
            if(cnt == ind2) val2 = b[j];
                
            j++; cnt++;
        }
    }
    
    while(i<n1){ //check if remaning part for first array.
        if(cnt == ind1) val1 = a[i];
        
        if(cnt == ind2) val2 = a[i];
        
        i++; cnt++;
    }
    
    while(j<n2){ //for second.
            if(cnt == ind1) val1 = b[j];
        
        if(cnt == ind2) val2 = b[j];
            
        j++; cnt++;
    }
    
    
    if(n%2 == 0){ //now. if n1+n2 is even that means we need to return both val1 and val2 by 2.
        return (double)((val1+val2)/(double)2);
    }
    else return (double)val2; //else simply return val2 i.e value at ind2

}


// Approach 3: brute force approach TC-O(N+M) SC-O(N+M)
//Simple approach of merging two soreted arrays.
double medianOf2(vector<int>& a, vector<int>& b) {
    vector<int>merged;
    
    int n=a.size(), m=b.size(), i=0, j=0;
    
    while(i<n && j<m){
        
        if(a[i] <= b[j])
            merged.push_back(a[i++]);
        
        else 
            merged.push_back(b[j++]);
    }
    
    while(i<n) merged.push_back(a[i++]);
    while(j<m) merged.push_back(b[j++]);
    
    int len = merged.size();
    
    double ans = 0;
    
    if(len%2 == 0){
        //even size length.
        ans = (merged[len/2]+merged[len/2-1])/(double)2;
    }
    else
        ans = merged[len/2];
    
    return ans;
}


