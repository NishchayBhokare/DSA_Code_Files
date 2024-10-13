//find duplicate elements ranging from 1 to n.
//Leetcode.


//Approach 1: we are marking duplicate element - 1 as -ve..
//so if index is already -ve..then element is duplicate...
//this solution is applicable for range in between 1 to n.
//we are doing index-1 because we cannot store element at nth index..and as
//range is from 1 to n..so 0 is not there..so we can store 1 element at 0 index
//by doing element - 1.
vector<int> findDuplicates(vector<int>& arr) {
          vector<int>ans;
        int n = arr.size();
        for(int i = 0; i<arr.size(); i++){
           if(arr[abs(arr[i]) -  1] < 0) { //if current element - 1  index value is 
           //less than 0..then current element is duplicate..so take it's absolute value and store in answer array.
               ans.push_back(abs(arr[i]));
           }
           else arr[abs(arr[i]) - 1] *= -1; //else mark current element - 1 index as -1.
        }
      
        if(ans.size() > 0) return ans; //if size of ans is greater than 0 then return ans
        return {}; //else return empty arrray .
    }

//Approach 2: upading input array by inserting one element..so range can be from 
// 1 to n-1..we already solved this problem
 vector<int> findDuplicates(vector<int>& arr) {
         vector<int>ans;
         arr.push_back(0); //updating array by inserting one element.
         int n = arr.size();
        for(int i=0; i<n; i++){ //looping 
            int index=arr[i]%n; //extracting index for that ith element, taking modulus of n because, to get orginal value present at that ith index in original given array.
            arr[index]+=n; //after extracting index, at that index adding n i.e length of given array.
        }
        for(int i=0; i<n; i++){
            // float f= arr[i]/(n*1.0);
            // if(i == 0 && f > 2) ans.push_back(n);
            // if(i != 0 && f > 2) ans.push_back(i); //so no need of doing this.
              if( (arr[i]/n) >= 2) ans.push_back(i); 
        }
        
        if(ans.size()==0) return {}; 
        
        return ans; //else, return ans with duplicate element. 
    }

    //Approach 3: as elements ranging from 1 to n so..if nth integer is dulicate so
//if n=3 then 3%3 will be 0 so we're incrementing a[0]+n...that's why if index i==0
//and its divisible is greater than 2 then return n and for remaing cases return 
//that index itself.

vector<int> findDuplicates(vector<int>& arr) {
        vector<int>ans;
        int n = arr.size();
    for(int i=0; i<n; i++){ //looping 
        int index=arr[i]%n; //extracting index for that ith element, taking modulus of n because, to get orginal value present at that ith index in original given array.
        arr[index]+=n; //after extracting index, at that index adding n i.e length of given array.
    }

for(int i=0; i<n; i++){
            float f= arr[i]/(n*1.0); //mulitiplying with 1.0 so that we can get divisible in decimal after point.
            //because if we add n + n for eg. if we are on 5th index...and on 5th index if 5 element is present...then
            //we need to add 5+5 = 10..So it does not mean...5 is duplicate element..because 
            //it present only one time...so that's why we're taking divisible in decimal..for 
            //correct preecision..

            if(i == 0 && f > 2) ans.push_back(n);
            if(i != 0 && f > 2) ans.push_back(i);
        }
        
        if(ans.size()==0) return {}; 
        
        return ans; //else, return ans with duplicate element. 
  }
