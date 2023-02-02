//Example for count the number of bits needed to be flipped to convert A to B.
//GFG
#include<iostream>
using namespace std;

 //Approach 1:- Most Efficient.  using bitwise ^ (xor) operator and count variable. TC- O(logn) SC is constant.
    int countBitsFlip(int a, int b){
      int count=0;
      int XOR = a ^ b; //taking xor of a and b. cause no. of 1 in xor will represent how many flips should required. 
      // bits in xor will only 1 if there is differnce between bits of a and b. cause xor of same bit is always 0 and xor of different bits is 1.
      // i.e 1 ^ 1 =0 or 0 ^ 0=0 and 1^0=1 and vice versa.
      while(XOR !=0) { //now looping till xor not get zero. (this function works as finding no. of set bits in an element.)
          if(XOR & 1) count++;  //if bit is 1 then we will increment count.
          XOR=XOR >> 1; //doing right shift.
      }
      return count;
    }
    
    
    //Approach 2:- comparing every bit of a with b. TC- O(logn) SC is constant.
    int countBitsFlip(int a, int b){
      int bitA, bitB, count=0;
      while(a !=0 || b !=0){ //looping till any of the varible not equal to zero.
          bitA= a & 1; //taking right most bit of 1.
          bitB= b & 1; //similary for b.
          if(bitA != bitB) count++; //now checking whether both bits are same or not. if not, then increment count. else skip.
          a=a>>1; //doing right shift.
          b=b>>1; //similarly.
      }
      return count; //finally return count.
    }
    
    
    //Approach 3 :- using builtin_popcount function. TC- O(logn) SC is constant.
     int countBitsFlip(int a, int b){
     return (__builtin_popcount(a^b)); // this will directly count the set bits of xor of the two numbers.
     }