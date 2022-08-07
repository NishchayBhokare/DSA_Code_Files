#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter a number" << endl; // we will take no. by cin.
    cin >> n;
    n = abs(n); // ignoring -ve sign.
    float ans = 0, i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    } // taking binary representation for given no. by ignoring -ve sign.

    int ans2 = ~(int)ans; // by using bitwise not operator we can convert it into binary representation for -ve no.
    //    cout<<ans<<endl; //binary representation by assuming given number is positive number.
    cout << "binary representation for -ve no. is " << ans2 << endl; // binary representation for negative number.

    int j = 0, dec = 0;
    while (ans2 != 0) //now converting resultant binary to decimal.
    {
        int bit = abs(ans2) % 10; //getting bit by bit from binary representation.
        if (bit == 1) //if bit is 1 then we are taking its power.
        {
            dec = dec + pow(2, j);
        }
        ans2 = ans2 / 10; //reducing bit after recieved it.
        j++; //moving j.
    }
    cout << "Decimal representation for -ve no. is " << (-dec); //multiplying with -ve sign cause given no. is -ve.
}
