// Example for counting total number of 1 bits in binary representation.
// link-
    // https://practice.geeksforgeeks.org/problems/set-bits0143/1

//Approach 1:- using bitwise and. and right shfit operatror.
int setBits(int n) // TC is O(logn) and space is also constant.
{
    // Write Your Code here
    int count = 0; // initially count is zero. we are counting total numbers of 1 in binary representation of particualr number.s
    while (n != 0)
    { // looping till n not get 0. At one time n will be zero cause we are doing right shift.
        if (n & 1)
        {            // now doing bitwise "&" between last bit and 1 so for eg. if last bit of binary representation is 1 then 1 & 1 is 1 so count will increment and if last bit is 0 then 0 & 1 will be 0 so, count will not increment.
            count++; // incrementing.
        }
        n = n >> 1; // doing one time right shift and assigning it to n.
    }
    return count; // finally returning count.
}


//Approach 2:- using modulus and divide. // TC is O(logn) and space is also constant.
     int setBits(int n) {
        int count=0;
        while(n!= 0){
            int bit=n % 2; //by taking modulus with 2 we will get remainder which will our binary no.
            if(bit==1) count++;
            n/=2; //if n=10 then by dividing we will get n=5, 2 , 1, 0.
        }
        return count;
    }


//Approach 3:- Most Efficient approach. (Brian_kerninghan algo.) TC: O(no. of setbits) SC is constant.
    //In this example. n = n & n-1 . with this statment we will reduce set bits from right of n. i.e if n contains set bit 4 then after 1 iteration it will contain 3. that's why its TC is no. of set bits.
    //for eg. if n=10 i.e 1010 then 1010 & n-1 i.e 1010 & 1001 = 1000 (reduced right most one set bit) 
    //again enter in loop, 1000 & n-1 i.e 1000 & 0111 = 0000. so n=0. and we will stop and count is 2. cause we enter in loop 2 times.
        int countSetBits(int n)
        {
            int count = 0;
            while (n > 0) { //looping till n not equal to 0.
                count++;
                n = n & (n - 1);
            }
            return count;
        }

