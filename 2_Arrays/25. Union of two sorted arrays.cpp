//GFG -> Union of 2 Sorted with Duplicates

//Approach 1: optimised Approach. TC-O(n+m) SC-O(n+m).
vector<int> findUnion(vector<int> &a, vector<int> &b) {

    vector<int>ans;
    
    int i=0,j=0;
    int n=a.size(), m=b.size();
    
    while(i<n && j<m){
        
        if(a[i] == b[j]){ //if elements are same then push any element and increment both pointers.
            
            ans.push_back(a[i]);
            i++; j++;
        }
        
        else if(a[i] < b[j]) //if ith element is less than jth element. then push ith element in ans.
            ans.push_back(a[i++]);
            
        else 
            ans.push_back(b[j++]); //else jth element.
            
        while(i>0 && i<n && a[i]==a[i-1]) //also we have to insert distinct element in union arrya. so 
        //increment i till we're getting duplicate elemetn.
            i++;
            
        while(j>0 && j<m && b[j]==b[j-1]) //same for j.
            j++;
    }
    
    while(i<n){ //also check..if element are still there in first array or not.
        if(a[i] != a[i-1]) //if yes..then push non duplicate element in ans.
            ans.push_back(a[i]);
        i++;
    }
    
    while(j<m){ //same for j.
        if(b[j] != b[j-1])
            ans.push_back(b[j]);
        j++;
    }
    
    return ans;
}
    
//Approach 2: Another optimised Approach with slight changes. TC-O(n+m) SC-O(n+m).
vector<int> findUnion(vector<int> &a, vector<int> &b) {

    vector<int>ans;
    
    int i=0,j=0;
    int n=a.size(), m=b.size();
    
    while(i<n && j<m){
        
        if(a[i] == b[j]){
            
            if(i==0 || a[i] != ans.back()) ans.push_back(a[i]); //here slight change is..while pushing only..we're checking.
            //whether ith element is already present at ans of back or not. if not then only push.
            //i==0 condition is for..when i==0 then ans.back() will be empty.
            i++; j++;
        }
        
        else if(a[i] < b[j]){
            
            if(i==0 || a[i] != ans.back()) ans.push_back(a[i]); //same here
            i++;
        }
            
        else{
            if(j==0 || b[j] != ans.back()) ans.push_back(b[j]); //same here
            j++;
        } 
            
    }
    
    while(i<n){
        if(a[i] != a[i-1])
            ans.push_back(a[i]);
        i++;
    }
    
    while(j<m){
        if(b[j] != b[j-1])
            ans.push_back(b[j]);
        j++;
    }
    
    return ans;
}
    

//Approach 3: Using set. TC-O((n+m)log(n+m)) SC-O(n+m).
vector<int> findUnion(vector<int> &a, vector<int> &b) {

    vector<int>ans;
    set<int>st;
    
    for(auto i:a)
        st.insert(i);
        
    for(auto i:b)
        st.insert(i);
        
    
    for(auto i:st)
        ans.push_back(i);
    
    return ans;
}
    