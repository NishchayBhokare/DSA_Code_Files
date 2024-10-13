//left shift means multiplying by 2. and right shift means dividing by 2.
//And -> & , OR-> | , xor ->  ^.
// Example for conversion of binary number to decimal.
// link-
// https://practice.geeksforgeeks.org/problems/binary-number-to-decimal-number3525/1


// this is program when binary number is given in string format.
int binary_to_decimal(string str)
{ // TC- O(n) and no space
    // Code here.
    int i = 0, ans = 0;
    for (int j = str.length() - 1; j >= 0; j--, i++)
    { // looping from back to front.
        if (str[j] == '1')
            ans = ans + pow(2, i); // if digit is 1 then we will take pow of that particular digit/bit with addition of ans and assigning back to  ans.
    }
    return ans; // returning our ans. which contain all addition i.e our decimal number.
}

//by using range based loop.
 int binary_to_decimal(string str) {
        int ans = 0;
        int i = str.length() - 1;
        for(auto ch:str){
            if(ch == '1'){
                ans += pow(2,i);
            }
            i--;
        }
        return ans;
}

//Another solution by first calculating maximum value of first set bit and then divide it..
 int binary_to_decimal(string str) {
        int ans = 0;
        int i = str.length() - 1;
        int max = pow(2,i); //calculating bit set bit value.
        
        for(auto ch:str){
            if(ch == '1'){
                ans += max; //and add that value in ans..if ch is 1.
            }
            max = max / 2;
             //on every iteration divide max by two..because we're traversing from left to right.
             //we can write like this also max = max >> 1; meaning is same.
        }
        return ans;
    }

// below code for if given binary representation is in int data type.
#include <iostream>
#include <math.h>
using namespace std;
int main() //program when binary representation is in the form of number and not in string.
{
    int n;
    cout << "Enter a binary number" << endl;
    cin >> n;
    int ans = 0;
    int i = 0;
    while (n != 0)
    {
        int digit = n % 10;  //by modulus of 10 we will get remainder which is last digit of particular number.
        if (digit == 1)
        {
            ans = ans + pow(2, i);  // if digit is 1 then we will take pow of that particular digit/bit with addition of ans and assigning back to  ans.
        }
        n = n / 10; // now we are dividing n with 10 and assigning it to again n. so that we can reduce one digit from it.
        i++; //moving i so that we can take power for next element.
    }
    cout << ans; //priniting ans.
}