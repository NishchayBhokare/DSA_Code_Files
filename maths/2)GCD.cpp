//Example to find Greatest Common Divisor(GCD) or Highest Common Factor(HCF).
//GFG

//Approach 1:Most Efficient algo. using Euclidean algo. by modulus operation. TC - O(log(min(a,b))) SC - O(1)
 
	int solve(int a, int b){ 
	    
	   while(a!= 0 &&  b!= 0){ //looping till both not equal to zero, cause any of the no. is zero that means we got gcd which will be either a or b.
	        
	        if(a > b) a = (a%b); //if a greater than b, do modulus between a,b and store remainder to a.
	        else b = (b%a); //similarly opposite when b greater than a.
	    }
	    if(a==0)return b; //finally when we get any of the no. is zero, then check if a is zero then return b.
	    return a; //else return a.
	}	
    int gcd(int a, int b) 
	{ 
	    return solve(a,b); 
	} 


//Approach 2: Using recursion. TC-O(log(min(a,b))) SC-O(log(min(a,b)));
 int gcd(int a, int b) 
	{ 
        if(b == 0) return a;
        gcd(b,a%b);

       // return b == 0 ? a : gcd(b, a % b); single line answer.
	} 



//Approach 2: Euclidean algorithm by subtraction. TC - O(min(a,b)) SC - O(1)
int solve(int a, int b){
	    
	    if(a == 0) return b; //if a is zero then return b. cause that will be common factor. for eg, if a = 0 and b=6 then common factor is 6.
	    if(b == 0) return a; //similarly for b.
	    while(a != b){ //looping till a not equal to b, cause when we get a equals to b that means we reach to the greatest common factor between a and b.
	        
	        if(a > b) a = (a-b); //if a is greater than b, then subtract b from a.
	        else b = (b-a); //else substract a from b.
	    }
	    return a; //at the end return a or b, cause we reach to the condition where a and b is equal.
	}
    int gcd(int a, int b) 
	{ 
	    return solve(a,b); 
	} 

