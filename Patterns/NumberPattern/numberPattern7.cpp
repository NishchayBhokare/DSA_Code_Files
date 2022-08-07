#include<bits/stdc++.h>
using namespace std;

// 111
// 222
// 333
// 444

int main(){
    int i=0;
    int n;
    cin>>n;
    while(i<=n){ //i to n-1 showing total number of rows.
        int j=1;
        while (j<=n) //j to n-1 showing total number of columns.
        {
            cout<<i<<" "; // it will print 000 111 and so on. on every new line.
            j++;
        }
        cout<<endl;  //after printing 1 row i.e 4 columns then we will change line to start from next line. 
        i++; 
    }
}