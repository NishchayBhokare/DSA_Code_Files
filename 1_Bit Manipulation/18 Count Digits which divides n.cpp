//GFG. 
//Count Digits. check if all digits of n. divides n in such a way that remainder will be 0.
//so return those count of digits which divides n completely.
int evenlyDivides(int n) {
    int m=n, cnt=0;
    
    while(m){
        
        int d = m%10;
        
        if(d!=0 && n%d == 0) //digit should not be zero. 
            cnt++;
        
        m=m/10;
    }
    
    return cnt; 
}