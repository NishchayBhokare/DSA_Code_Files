//GFG.

//Approach 1: Optimised appraoch. TC-O(Logn) SC-O(1)
//1. find out range.
//2. find out position of number.
//3. get that number and find out position of digit.
//4. return that digit.
class Solution {
  public:
    char nthCharacter(int n) {
        // code here
        
        long long digit=1;
        long long start=1;
        long long count=9;
      
        while(n > (digit*count)){ //it will check like n>(1*9) i.e n>9 then n>(2*90) i.e n>180
            //why 180, total 2 digit number we have 90 so total digit will be 90 * 2 = 180.
            
            n -= (digit*count); //substract current range and move on to next range.
            
            start*=10;
            count*=10;
            digit++;

        }
  
        long long numInd = (n-1)/digit; //get position of number.
        
        long long number = start + numInd; //get that number
        
        long long pos = (n-1)%digit; //find position of digit.
        
        string str = to_string(number); //convert this current number into string so that we can return 
        //digit by index.
            
        return str[pos]; //return answer.
    }
};



//Approach 2: Bruteforce approach TC-O(N) SC-O(n)
char nthCharacter(int n)
{
    // Store the concatenated string.
    string s = "";

    // Start generating numbers from 1.
    int num = 1;

    // Continue until the string has at least n characters.
    while (s.size() < n)
    {
        // Append the current number to the string.
        s += to_string(num);

        // Move to the next positive integer.
        num++;
    }

    // Return the nth character using 1-based indexing.
    return s[n - 1];
}
