// Example for Subtract the Product and Sum of Digits of an given Integer Number.
// link- (on leetcode)
    // https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/



int subtractProductAndSum(int n) // TC is constant and space is also constant.
{
    int product = 1, sum = 0; // initializing product with 1 and sum with 0.
    while (n != 0)
    {                       // i.e looping till not 0 digit present in n. so that we can get all degits of particular number.
        int digit = n % 10; // by modulus of 10 we will get remainder which is last digit of particular number.
        product *= digit;   // now, doing multiplication between product and current digit.
        sum += digit;       // similarly in case with addition.
        n = n / 10;         // now we are dividing n with 10 and assigning it to again n. so that we can reduce one digit from it. cause we already perform sum and product for that particular number.
    }
    return (product - sum); // returning difference between product and sum.
}