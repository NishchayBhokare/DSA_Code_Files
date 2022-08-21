 //Example for make unset bits to set in x for given range in y. 

 //Approach 1: using left shift r+1 time. TC: O(1) and SC O(1)
     int setSetBit(int x, int y, int l, int r){
         long mask=1; // creating mask which is initially 1. cause when we left shift mask, then set bit 1 should prsent r+1 position i.e if r is 4 then pos. of set bit should be 5.
         mask=mask<<(r-l+1) ; //left shifting shifting mask r-l+1 times. 
         mask--; //decrement mask so that  for eg. 10000 convert into 1111.
         mask=(mask<<(l-1));  //after creating mask, we need to add zeros from right of its, iff l is greater than 1. cause if l is in somewhere between then to reach there we need to add 0's from right side of mask so that mask will reach there.
                              //we will do left shift l-1 times times. i.e we will add 0's.
         mask= y & mask; //it will give you bits of y, which is in range of l to r. and this is what we want.
         mask=x | mask; // by taking bitwise or, we set bits which are unset in x but set in y within given range.
         return (int) mask; //returning mask after type casting in int.
         //we created mask of long, cause to handle case when r is 32 and l=1 so, that time we will shift mask 33 times which will go beyound size of int. so to handle this case we created mask of long which has size 8 bytes i.e 64 bits.
     }
         
    
//Approach 2: using left shift with adding 1. TC: O(r-l) and SC O(1)
 int setSetBit(int x, int y, int l, int r){
        // code here
        int sizeMask= r-l+1; //showing size of mask.
        int mask=0; //creating mask which is initially 0.
        while(sizeMask--){ //looping till sizeMask not becomes 0.
            mask=mask<<1 | 1; //shifting mask and also taking "bitwise or" so that we can add set bit successufully on every iteration cause we want mask of size sizeMask and it should contains all 1 i.e set bits.
        }
        
        int addZero = l - 1; //after creating mask, we need to add zeros from right of its, iff l is greater than 1. cause if l is in somewhere between then to reach there we need to add 0's from right side of mask so that mask will reach there.
        mask=mask<<addZero; //we will do left shift addZero times. i.e we will add 0's.
        
        int updMask= mask & y; //it will give you bits of y, which is in range of l to r. and this is what we want.
        int result = updMask | x; //taking bitwise or, so if updated mask contains any set bits, then that will be set to x also.
        return result; //returning result which is updated x. i.e we set bits which are unset in x but set in y within given range.
    }

  //Analogy for approach 2:-
        //explanation if x=10 i.e 1010 and y=13 i.e 1101, l=2,r=4.
        //r-l+1=3. so mask is of size 3 i.e 111
        //now l is greater than 1 so l-1=1. so we will add one times zero from right side to mask. i.e updated mask will be 1110.
       //and finally take or of updated mask and x i.e 1 1 10 | 1010  = 1110 i.e 14.                                      
