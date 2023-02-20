//Example to calculate fast exponentiation and modular exponentition.
//Code studio and gfg

//a^b = a^(b/2)^2   -->when b is even
//a^b = a^(b/2)^2 * a.  -->when b is odd. i.e additionally multiply by a.

//Approach 1: Most optimised approach TC-O(logn) SC-O(1).
int modularExponentiation(int x, int n, int m) {
	int ans=1;
	while( n > 0){
		if(n & 1){ //when n is odd.
			ans= (1LL*ans*x)%m;	
		}
		x=(1LL*x*x)%m;
		n>>=1; //dividing n by 2.
	}
	return ans;
}


//Approach 2: Using Recursion. TC-O(logn) SC-O(logn).
int modularExponentiation(int x, int n, int m) {
	if(n == 0) return 1;

	int answer=modularExponentiation(x,n/2,m);

	if(n % 2 == 0){
		return (1LL * answer * answer)%m;
	}
	else{
		return (1LL * (1LL * answer * answer) % m * x % m) % m;
	}	
}

//Approach 3: Brute force solution. TC-O(N) SC-O(1)
int modularExponentiation(int x, int n, int m) {
	int answer = 1;
	// Iterating 'N' times.
	for (int i = 1; i <= n; i++) {
		// Multiply answer with 'X' and then do modulo with 'M'.
		answer = (1LL * answer * x) % m;
	}
	// Return the answer.
	return answer;
}


//GFG version
//Iterative answer
long long int PowMod(long long int x,long long int n,long long int m)
{
	int ans=1;
	while(n){
		if(n & 1){
			//odd
			ans=(ans*x)%m;
		}
		x=(x*x)%m;
		n=n>>1;
	}
	return ans;
}


//Recursive way.
long long int PowMod(long long int x,long long int n,long long int m)
{
	if(n == 0) return 1;
	
	long long int answer=PowMod(x,n/2,m);
	if(n % 2 == 0){
		return (answer*answer)%m;
	}
	else{
		return ( (answer * answer) % m * x % m) % m;
	}
}

