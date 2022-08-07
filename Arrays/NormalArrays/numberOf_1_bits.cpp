// Example for counting total number of 1 bits in binary representation.
// link-
    // https://practice.geeksforgeeks.org/problems/set-bits0143/1


int setBits(int n) // TC is constant and space is also constant.
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