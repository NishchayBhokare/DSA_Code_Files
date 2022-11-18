#include<iostream>
using namespace std;

//Approach 1: using loops
// int main(){
//     int a=3;
//     int b=3;
//     // cout<<"Enter two numbers "<<endl;
//     // cin>>a>>b;
//     int ans = 1;
//    for(int i=0; i<b; i++){
//     ans = ans * a;
//    }
//     cout<<"power of "<<a<<" raised to "<<b<<" is "<<ans<<endl;
//     return 0;
// }




//Approach 2: using recursion
int powerOf(int a,int b){
    //Base case 
    if(b == 0) return 1;

    int ans = a * powerOf(a,b-1);

    return ans;
}


//Approach 3: Most Optimzed approach
int powerOf2(int a, int b){
    if(b==0) return 1;

    int ans = powerOf2(a,b/2);

    if((b & 1) == 0){ //if b is even then enter in if block otherwise enter in else block
        ans = ans * ans; //This is nothing but ans = 2 raise to b/2 * 2 raise to b/2.
        return ans;
    }
    else{
        ans = a * ans * ans;//This is nothing but ans= 2 * 2 raise to (b/2) * 2 raise to b/2.
        return ans;
    }
}

//Approach 4: with 4 recursive calls
int powerOf3(int a, int b){
    if(b==0) return 1;

    if( (b & 1) == 0){ //if b is even then enter in if block otherwise enter in else block
        int ans = powerOf3(a,b/2) * powerOf3(a,b/2); //This is nothing but ans = 2 raise to b/2 * 2 raise to b/2.
        return ans;
    }
    else{
    int ans = a * powerOf3(a,b/2) * powerOf3(a,b/2);//This is nothing but ans= 2 * 2 raise to (b/2) * 2 raise to b/2.
        return ans;
    }
}



int main(){
    int a=2;
    int b=5;

    cout<<powerOf(a,b)<<endl;
    cout<<powerOf2(a,b)<<endl;
    cout<<powerOf3(a,b);
}