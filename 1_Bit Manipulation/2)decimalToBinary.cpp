// Example for conversion of decimal number to binary.
// link-
// https://practice.geeksforgeeks.org/problems/decimal-to-binary-1587115620/1
#include<iostream>
#include<math.h>
using namespace std;
void toBinary(int n) //TC- O(n) and no space
{
    int ans = 0;
    int i = 0;
    // Approach 1 : -by doing bitwise "&" and right shift operator.TC - O(log n) and SC is constant.
    while (n != 0)
    { // looping till n not get 0. At one time n will be zero cause we are doing right shift.

        int bit = n & 1;                // now getting first right most bit and storing it to bit variable.
        ans = (pow(10, i) * bit) + ans; // this formula is used to reverse a bit cause we're getting binary number in reverse order so to correct it we need to again reverse it.
        // for eg. 10 has 1010 binary representation. but we will get 0101 so to reverse this representation we're using above function.
        n = n >> 1; // doing right shift one time.
        i++;        // also moving i to next of it.
    }
    printf("%d", ans); // printing our ans.
    // cout << ans;


    // Approach 2:- by taking modulus and division. TC- O(log n) and SC is constant.
    while (n != 0)
    { // looping till n not get 0. At one time n will be zero cause we are doing right shift.

        int bit = n % 2;                // by doing number modulus by 2 we will get remainder which will be our first bit. and we will loop to get all bits.
        ans = (pow(10, i) * bit) + ans; // this formula is used to reverse a bit cause we're getting binary number in reverse order so to correct it we need to again reverse it.
        // for eg. 10 has 1010 binary representation. but we will get 0101 so to reverse this representation we're using above function.
        n = n / 2; // we are dividing so that we will reach to n=0 and also we will get all bits in bit variable.
        i++;       // also moving i to next of it.
    }

    printf("%d", ans); // printing our ans.
    //   cout<<ans;
}


//converting -ve number into binary format.
    int n = -6; //suppose number is -6 which has representation 1111111010
    n = -1 * n; //converting into +ve number
    
    long long int ans = 0;
    
    long long int mask = (pow(2,10) - 1); //suppose we want to represent binary 
    //by 10 digit format. so before getting xor..create masked 1111111111 
    long long int onesComp =  n ^ mask; //take xor so bits can fliped.
    long long int twosComp = onesComp + 1; //now add 1 to onesCompliment..
    
    for(int i = 0; i<=10; i++){ //traverse
        int bit = twosComp & 1; //take bit.
        ans = bit * pow(10,i) + ans; //use this formulat to take bit and create answer.
        twosComp >>= 1; //shift one time.
    }
    
    cout<<ans; 