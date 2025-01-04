//GFG.
 
//Approach 1: Using prefix and suffix sum. here product. TC-O(N) SC-O(1)
//If you carefully observe-> there are three situations. 
// 1) if all elements are positive then max product will be product of all elemetns.
// 2) even number of -ve elements. In this case also..max product will be all numbers. because two -ve values product will be +ve.
// 3) odd number of -ve elemnts. In this case. we have to skip one -ve element to get maximum product.

//so if you dryrun questions by using prfix product and suffix product approach. you will get. maxproduct.
//why we're doing prefix and suffix product, because if there is case of odd number of -ve element.
//then if you skip this -ve element. then array will be divided into two parts. left and right.
//so if we take suffix till that element and prefix till that element then we will take maximum product among all.
//that's why this works.
int maxProduct(vector<int> &arr) {

    int n=arr.size();
    int preProd = 1, suffProd=1, maxProduct=INT_MIN;
    
    for(int i=0; i<n; i++){
        preProd = preProd * arr[i];
        suffProd = suffProd * arr[n-i-1];
        
        maxProduct = max({maxProduct, preProd, suffProd}); //take maximum from all.
        
        if(preProd == 0) preProd = 1; //edge case is, if preprod equasl to 0 then make it as 1.
        if(suffProd == 0) suffProd = 1;
    }
    
    
    return maxProduct;
}

//Approach 2: Using advanced version of kadens algo..

//here logic is we're using two varaibles.
//mini and maxi. mini stores miniimum product where as maxi stores maximum product.
//and if there is -ve element then we will swap it.
//why we're doing this because. -ve element * min value is greater than -ve elemnt * maxValue.
//so before doing this operation make sure to swap both this varaibles.

//now take max of current element and maxi*current eleemnt.
//why it's like this. there are two situtations are possible. either we will start new subarray from this elemnet
//or either we are continuing subarray started in past. so take maximum of it.
//same for mini.
int maxProduct(vector<int> &arr) {

    int n=arr.size();
    int maxProduct=arr[0], maxi=arr[0], mini=arr[0];
    
    for(int i=1; i<n; i++){
        
        if(arr[i] < 0)
            swap(maxi,mini);
        

        maxi = max(arr[i], maxi*arr[i]);
        mini = min(arr[i], mini*arr[i]);
            
        maxProduct = max(maxProduct, maxi);    
    }
    
    
    return maxProduct;
}