//GFG.
//The number is armstrong, if we take cube root of every digit from number then we will get sum
//equals to given n.
bool armstrongNumber(int n) {
        
    int m=n, sum=0;
    
    while(m){
        
        int d = m%10;
        sum += pow(d,3); //we can write d*d*d.
        
        m/=10;
    }
    
    
    return sum==n;
}