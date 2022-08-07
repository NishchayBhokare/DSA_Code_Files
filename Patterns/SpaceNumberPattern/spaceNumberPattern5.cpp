#include<iostream>
using namespace std;

//    1
//   121
//  12321
// 1234321

 // for(int j=1; j<=(i*2-1); j++){
        //     cout<<j<<" ";
        // }

int main(){
    cout<<"Enter a number\n";
    int n;
    int count=0;
    cin>>n;
    for(int i=1; i<=n; i++){
         int space=n-i; //space is n-i i.e initially space is 3. so it will print 3 space and then 2 , 1 and so on till greater than 0.
         //print first space.
        while (space) //
        {
            cout<<" "; 
            space--;
        }


        //1st triangle
        for(int j=1; j<=i; j++){ //looping till less than or equal to i to get half work done.
            cout<<j;
        }
        // by above loop we can get below diagram.
        //    1
        //   12
        //  123
        // 1234

        //2nd triangle
        for(int k=i-1; k>0; k--){ //to get done remaining work we will loop from i-1 to greater than 0.
            cout<<k;
        }
        cout<<endl; //to change line.
    }
}