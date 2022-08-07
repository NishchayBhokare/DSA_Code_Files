#include<bits/stdc++.h>
using namespace std;

// * * * 
// * * *
// * * *
int main(){
    int i=0;
    int n;
    cin>>n;
    while(i<n){ //i showing total number of rows.
        int j=0;
        while (j<n) //j showing total number of columns.
        {
            cout<<"* ";
            j++;
        }
        cout<<endl;  //after printing 1 row i.e 4 columns then we will change line to start from next line. 
        i++;
    }
}