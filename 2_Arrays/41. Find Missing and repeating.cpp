//GFG.
//From given array find first repeting and missing number.

//Approch 1: Using Bit manipulation. xor technique. TC-O(N) SC-O(1)
 vector<int> findTwoElement(vector<int>& arr) {
    
    int n=arr.size(), xr = 0;
    
    //Step1: Take xor of all elements.
    for(int i=0; i<n; i++){
        xr = xr ^ arr[i]; //take xor for all element in array
        xr = xr ^ (i+1); //also take xor for first n numbers.  1 to n.
        //for eg. if array is 1 2 3 4 4
        //we will take xor like 1 ^ 2 ^ 3 ^ 4 ^ 4 
                            //  1 ^ 2 ^ 3 ^ 4 ^ 5
        //at the end..all element will get cancel out except. 4 and 5 last column. and we have to find this.
        //as at the end. xr will be 4^5 and we cannot differentiate here.
    }

    
    //Step2: calculate first different set bit.
    int diffSetBit = xr & ~(xr-1); //here we found first differentiateed bit in 4 and 5.
    // The bitwise NOT operator changes each 0 bit to 1 and each 1 bit to 0.
    
    
    //Step3: Differentiate elements based on diffSetBit. by taking and.
    int first=0, second=0;
    
    //take and for array elements - here we will 
    for(auto i:arr){
        
        if((diffSetBit & i) == 0){ //0th club elements. why & because we want to differential number based on that setbit.
            first = first ^ i; //then after take xor.
        }
        else{
            second = second ^ i; //1th club elements which has 1 set bit.
        }
    }

    //take xor for first n elements. //by doing all these..we have seperate out missing and repeated element.
    for(int i=1; i<=n; i++){
        
        if((diffSetBit & i) == 0){
            first = first ^ i;
        }
        else
            second = second ^ i;
    }

    //because of previous two for loops. what happing is, 
    //(1 ^ 2 ^ 3 ^ 4 ^ 4) ^ (1 ^ 2 ^ 3 ^ 4 ^ 5) beccause of taking xor we're able to sepearate out.
    //repeating and missing number. by differentitating it with first different significant bit.
    //4-> 100 and 5->110 so here second last is different bit. so diffSetBit will be = 010.

    

    //Step 4: check who is duplicate and misssing among first and second.
    for(auto i:arr){
        
        if(i == first) //if we found first in array..that means this is repetative number because if
        //it was missing number..then it won't found in array
            return {first,second};
    }
    
    return {second,first}; //we will reach here..if first is missing number. 
    //as we have to return repetative element first. so just replace the posititon.
}


//Approach 2: Using Maths. TC-O(N) SC-O(1).
//we're solving this question using proper maths.
//first calculating x-y(repeating element - missing element.). i.e val1. then calculating x2 - y2. because without this. we cannot find values of
//x and y.
vector<int> findTwoElement(vector<int>& arr) {

    long long n=arr.size();
    
    long long sum1N=(n*(n+1))/2, sqrSum2N = ((n*(n+1)) * (2*n+1))/6;
    //storing sum and squares of first natural n numbers.
    
    long long sum1=0, sqrSum2=0;
    for(auto i:arr){ //storing sum and squares array elements.
        sum1+=i;
        sqrSum2+=(long long)i * i;
    }
    
    
    long long val1 = sum1 - sum1N; //val1 is nothing but x-y.
    long long val2 = sqrSum2 - sqrSum2N; //similarly for val2. x2 - y2.
    
    val2 = val2/val1; //here, x2-y2=val2, (x-y)(x+y)=val2,
    // putting x-y as val1,  (val1)(x+y) = val2. i.e  x+y = val2/val1. and storing this (x+y) value in val2.
    
    //here we have done x-y = val1
                    //+
                    //  x+y = val2 = 2x.-> 2x = val1+val2 i.e x = (val1+val2)/2.
    long long x = (val1 + val2)/2; //we will get value of x here. which is repeatating element.
    
    
    long long y = x - val1; //missing elment. here//x-y=val1 -> x-val1 = y. i.e y=x-val1;
    
    return {(int)x,(int)y};
}



//Appraoch 3: TC-O(N) SC-O(N)
//Using map. just count the frequency.
 vector<int> findTwoElement(vector<int>& arr) {

    int n=arr.size();
    unordered_map<int,int>ump;
    
    for(int i=0; i<n; i++) //first store frequency of every element.
        ump[arr[i]]++;
    
    vector<int>ans;
    int a,b;
    
    for(int i=1; i<=n; i++){
        
        if(ump.find(i) == ump.end()) //if element not found. then this is the missing element.
            a = i;
        
        else if(ump[i] == 2) //if element frequency is equals to 2 then this our repeating number.
            b = i;
    }
    
    ans.push_back(b);
    ans.push_back(a);
    return ans;
}