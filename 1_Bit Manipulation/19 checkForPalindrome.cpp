//GFG.
//check if number
bool isPalindrome(int n) {
    
    int revNum=0, m=n;
    while(n){
        
        int d = n%10;
        revNum = revNum * 10 + d;
        n/=10;
    }
    
    return revNum == m;
}