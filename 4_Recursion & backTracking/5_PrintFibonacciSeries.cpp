// Example for Print first n Fibonacci Numbers.
// link- gfg
// https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1

#include <bits/stdc++.h>
using namespace std;
//Fibonacii Series for this example:- 1 1 2 3 5 8 13 21 34.
// Approach 1- Using a & b variable.
vector<long long> printFibb(int n) // TC- O(n) SC- O(n).
{
    // sample fibonacci series is 1 1 2 3 5 8 13 21 34
    // i.e addition of previous two numbers.
    vector<long long> v;
    if (n == 1){
        v.push_back(1); // if given n is 1 then just simply return 1.
        return v;                                
    }
        
        long long a = 1, b = 1, nextNumber; // first initialize a and b with 1. in this example we are not considering 0.
        v.push_back(a);                     // push first element in vector.
        v.push_back(b);                     // push second element in vector.
        for (int i = 3; i <= n; i++)
        {                            // loop from 3 to n i.e for n=4 loop will execute 2 times.
            nextNumber = a + b;      // adding previous two numbers a and b.
            v.push_back(nextNumber); // pushing sum of both number in vector.
            a = b;                   // now updating a to b.
            b = nextNumber;          // and b to nextNumber i.e updating to sum of a & b
        }
    
    return v; // and finally returning the vector.
}


//Approach 2: Using only elements from vector.
vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long> v;
        v.push_back(1);
        if(n==1) return v;
        v.push_back(1);
        if(n==2) return v;
        for(int i=2; i<n; i++) { //looping from 2 to n-1 cause we already inserted 2 elements in vector.
            long long sum = v[i-1] + v[i-2]; //taking sum of previous element and previous of previous element.
            v.push_back(sum); //and adding those sum in vector.
        }
        return v;
    }


//Approach 3: without using extra space printing fibonacci series.
void fibonaciiPrint(int n){ 
    int a=0;
    int b=1;
    if(n >= 1) cout<<a<<" ";
    if(n >=2) cout<<b<<" ";
    for(int i=3; i<=n; i++){
        int c = a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
}

//Approach 4: using recursion. 
int fibonacci(int n)
{
     if(n==1 || n==2){
        return 1;
    }
    else{
        int ans =  (fibonacci(n-1)+fibonacci(n-2));  //taking addition of previous two by calling it.
        return ans;
    }

}

int main(){
    int n=6;

    for(int i=0;i<n;i++){
        cout<<" "<<fibonacci(i); //calling for every number from 0 to n-1, so that we can get fibonacii series rather than nth fibonacii number.
    }    
}