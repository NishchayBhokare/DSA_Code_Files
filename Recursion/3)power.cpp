//Example for power of 2 raise to n.
#include <bits/stdc++.h>
using namespace std;
//Power of 2 is nothing but 2 raise to n = 2 * 2raise to(n-1);
int solve(int n){

//Base case
if(n == 0) return 1;

n = 2 * solve(n-1); //so, calling for n-1 power so that we will reach till the n equals to zero and will return 1. eg. 2^3 = 2 * 2^2;

return n;
}


int main()
{
int n = 3;
cout<<solve(n)<<endl;
}
