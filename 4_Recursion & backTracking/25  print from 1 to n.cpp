//GFG.

//Approach 1: TC-O(N) SC-O(N)
void printNos(int n) {

if(n==0) return;

printNos(n-1);

cout<<n<<" "; //using tail recursion.
}


//Approach 2: TC-O(N) SC-O(N).
void solve(int i, int n){
    if(i>n) return;
    
    cout<<i<<" "; //head recursion.
    
    solve(i+1,n);
}

void printNos(int n) {
    
    solve(1,n);
}