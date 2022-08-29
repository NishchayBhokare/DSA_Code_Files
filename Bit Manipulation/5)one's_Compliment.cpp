#include<bits/stdc++.h>
#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
// Example for taking 1's compliment for all bits and return the number which come after taking one's compliment.

//Approach 1 - by creating mask variable. TC:- O(logn) SC is constant.
int onesComplement(int n)
{ 
    // 101 i.e n=5
    int m = n;    // creating m variable which refers to n.
    int mask = 0; // 000 //creating simple mask variable which contain 0 initially on all 32 bits.
    while (m != 0)
    {                         // looping till m not get 0.
        m = m >> 1;           // shifting m towards right so that m can be 0.
        mask = mask << 1 | 1; // whenever there is shifting for m. then we are also doing shifting for mask to left so that we can add 1 bit to it also.
    }
    int ans = (~n) & mask; // taking not of n so that all 0's convert into 1 and 1 to 0. so 111...010 & 0000...111  ans will be 2 (i.e 0000....010) for given number 5.
    return ans;
}


//Approach 2 - by creating mask in different variation. TC:- O(logn) SC is constant.
    int onesComplement(int n){
        //code here
        int temp=n,i=0,mask=0;
        while(temp){ //looping till temp not equal to 0.
            mask = pow(2,i) + mask; //taking power, for eg. if n=6 i.e 110 then our mask will be 7 i.e 111.
            i++;
            temp>>=1;
        } 
        return (mask ^ n); //taking xor(^) between mask and n. so that 110 ^ 111 = 001.
    }


//Approach 3 - by doing bitwise "&" and right shift operator.TC - O(log n) and SC is constant.
int onesComplement(int n)
{
    int ans = 0, i = 0;
    while (n != 0)
    {
        int bit = !(n & 1); //taking right most bit and performing not operation on that bit cause we want compliment. i.e if bit is 1 then !(1) is 0.
        if (bit == 1) //if bit is 1 then we need to store pow of that index in ans.
        {
            ans = pow(2, i) + ans; //storing power of that ith index in ans.
        }
        i++; //moving i which is acts as index.
        n = n >> 1; //right shift.
    }
    return ans;
}


// Approach 4 - Using Reminder-divident method. TC- O(logn) SC is constant.
int onesComplement(int n)
{
    int ans = 0, i = 0;
    while (n != 0)
    {
        int bit = !(n % 2); // by doing number modulus by 2 we will get remainder which will be our first bit. and we will loop to get all bits.
        if (bit == 1)
        {
            ans = pow(2, i) + ans;
        }
        i++;
        n = n / 2; // we are dividing so that we will reach to n=0 and also we will get all bits in bit variable. 
    }
    return ans;
}


  // Approach 5 - Using Bit manipulation and divident method. TC:- O(logn) SC is constant.
    int onesComplement(int num) {
        int p=num,cnt=0; //storing num in p.
        while(num!=0){ 
            cnt++; //incrementing count.
            num/=2; //dividing num.
        }
        
        int k=pow(2,cnt)-1; //taking pow of 2 rest to cnt. i.e if cnt=3 then pow=2 rest to 3 is 8. and doing -1 from it i.e we will get 7 for above problem. if we do -1 from any number (except 0) binary representation is right most set bit will 0 and it followed by one. for eg. if n=8 then its binary Rep. is 1000. if we do -1 i.e n=7 then its binary Rep will be 111.
        return k^p; //k XOR P i.e 111 ^ 101 = 010. i.e 2.
    }