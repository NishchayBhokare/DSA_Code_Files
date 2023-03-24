//Example for Calculate square of a number without using * / and pow().
//On coding ninjas.

#include<bits/stdc++.h>
using namespace std;

// Apporach 1: Using left shifting. i.e num * 2^i. TC- O(logn) SC- O(1)
int calculateSquare(int num)
{
    int square=0,i=0,n=abs(num);  
    while(n!=0){ //looping till no. of digits in given no.
        if(n & 1){ //if lsb of given no. is 1 then enter in if block.
           square+=abs(num)<<i; //shifting num to left side i times. for eg. num=5 so BinRep is 101. then if n& 1 is 1, we will shift 101 to i times to left. i.e 5*2^0 + 5*2^2 = 5+20=25. i.e 5<<0 + 5<<2 = 25.
        }
        n=n>>1; //removing one by one digit from n.
        i++; //incrementing value of i.
    }
    return square; 
}


// Apporach 2: Using left shift 1 time for each iteration. i.e num * 2^1. TC- O(logn) SC- O(1)
//slight change in approach 1. i.e every time shifting num to left side 1 time. but if bit is 1 then only add value of num to square.
int calculateSquare(int num)
{
    if(num <0) num=-(num);
    int n=num,square=0;
   while(n!=0){
       if(n&1) square+=num;
       num=num<<1; //on every iteration num will shift by 1 to left side. i.e num * 2^1.
       n=n>>1; 
   } 
   return square;
} 


// Apporach 3: For num times taking num addition and storing it.(brute force) TC- O(N) SC- O(1) 
int calculateSquare(int num)
{
    int square=0, temp=abs(num);
    while(temp){//looping till temp times. i.e if temp=5 then looping 5 times.
        square+=abs(num); //on every iteration adding num to square. i.e for five times we will add 5+5+5+5+5 = 25, which is square of 5.
        temp--; //decreasing iteration of temp i.e 5 to 0.
    }
    return square; //and finally returning ans.
}

 

// int calculateSquare(int num)
// {
//     int ans = 0;
//     num = abs(num);
//     for(int i=0; i<num; i++){
//         ans += num;
//     }
//     return ans;
// }
