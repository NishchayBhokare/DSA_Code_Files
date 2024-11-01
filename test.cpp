#include<bits/stdc++.h>
using namespace std;
int findFactoril(int n){
    if(n == 1) return 1;

    int ans = n * findFactoril(n-1);
    return ans;
}

int findPower(int n){
    if(n == 0) return 1;

    int ans = 2 * findPower(n-1);
    return ans;
}
void findCounting(int n){
    if(n == 1){
        cout<<n<<endl;
        return;
    }

    cout<<n<<endl;
    return findCounting(n-1);
}

int main(){
    // cout<<findFactoril(4);
    cout<<endl;
    // cout<<findPower(3);
    findCounting(5);

    // cout<<"hello"<<endl;
    // int *pr = new int[3];
    // int *b = new int(2);
    // cout<<(*b)<<endl;
    // for(int i = 0; i<2; i++) cout<<pr[i]<<endl;;
    // return 0;
}