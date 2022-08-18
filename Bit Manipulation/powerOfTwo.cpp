// Example for checking given number is in power of 2 or not.
#include <iostream>
using namespace std;

// Approach 1 - (Most Efficient) Using Bit manipulation. TC:- O(1) Sc- O(1).
    // Analogy- 1) if number is in power of 2 then that number will have only one set bit. eg. n= 16 then 10000 is the binary representation which contain only 1 set bit. and if n=14 which is not power of 2 cause it has 1110 as representation, which contain more than 1 set bit.
    //  2) if we do -1 from any number (except 0) binary representation is right most set bit will 0 and it followed by one. for eg. if n=16 then its binary Rep. is 10000. if we do -1 i.e n=15 then its binary Rep will be 1111.
bool isPowerofTwo(long long n)
{
    if (n <= 0)
        return false; // handling case when n is 0 or less than that. so if true then return false cause it won't be power of 2.
    if ((n & (n - 1)) == 0)
        return true; // taking & of n and n-1 so by any point if we get value which not equal to zero (means particular number have more than 1 set bit. 1 & 1 == 1) then we will return false Otherwise true. for 14  B.Rep is 1110 and n-1 i.e for 13 B.Rep is 1101 then by doing 14 & 13 it is not equal to 0.
    return false;    // if not equal to zero.
}


// Approach 2 - Using Reminder-divident method. TC- O(logn) SC is constant.
bool isPowerofTwo(long long n)
{
    if (n == 0)
        return false; // handling initial case when n==0.then simply return false.
    while (n != 1)
    { // looping till "n" not equal to 1. cause if we reach to n=1 after keep dividing it,  that means n is in power of 2. cause we will only get remainder as 1, iff n is in power of 2.
        if (n % 2 != 0)
            return false; // if by any point if remainder is not equal to zero after dividing it n. then simply return false. cause number which is in power of 2 will always have remainder as 0 by taking n % 2.
        n = n / 2;        // dividing n to n/2 so that we can reach to last condition where n==1. i.e number is in power of 2.
    }
    return true; // if we are successfully get out from loop then yes number is in power of 2.
}


// Approach 3 - By keeping track of ans variable. TC- O(logn) SC is constant.
bool isPowerofTwo(long long n)
{
    if (n == 1)
        return true;   // handling case when n==1 cause we are starting our ans as 1. and after enter in loop our ans become 2 for 1st iteration. so we won't get condition when ans is 1. so that's why we are handling n==1 condition.
    long long ans = 1; // initially ans 1.
    for (ans = 1; ans < n;)
    {                  // looping till ans is less than n,cause if ans is greater than n and if did'nt meet condition as ans==n then simply we can say given number is not in power of 2.
        ans = ans * 2; // instead of taking power we are using previous ans and multiplying it by 2. so that it will identically work as power by reducing complexity.
        if (ans == n)
            return true; // if we got ans ==n that means givn no. is in power of 2.
    }
    return false; // and if we get out of loop that means we did'nt got no. in power of 2.
}