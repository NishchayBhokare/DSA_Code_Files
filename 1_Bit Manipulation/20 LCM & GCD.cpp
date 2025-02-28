//GFG. 
the LCM is the smallest integer that is evenly divisible by both a and b. For example,
LCM(240,60) = 240

The greatest common factor (GCF or GCD or HCF) of a set of whole numbers is the largest positive integer that divides evenly into all numbers with zero remainder.
GCD(240,60)= 60

//Approach 1: Most optimised Approach.
vector<int> lcmAndGcd(int a, int b) {
    
    int n=a, m=b;
    while(n && m){
        
        if(n>m)
            n=n%m;
        else
            m=m%n;
    }
    
    int GCD = max(n,m);
    
    int LCM = (a*b)/GCD; //if we divide multiplication of both number by GCD. we will get LCM.
    return {LCM, GCD};
}

//Appraoch 2: seperately calculating both.
vector<int> lcmAndGcd(int a, int b) {
    
    int n=a, m=b;
    vector<int>ans;
    
    while(n != m){
        
        if(n<m){
            n+=a;
        }
        else m+=b;
    }
    
    ans.push_back(n);
    
    n=a, m=b;
    while(n && m){
        
        if(n>m)
            n=n%m;
        else
            m=m%n;
    }
    
    ans.push_back(max(n,m));
    
    return ans;
}
    
