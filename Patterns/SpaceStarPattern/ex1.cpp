// First Program
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number" << endl;
    cin >> n;
    int i=1;
    while(i--){

        for(int j=1; j<=n; j++){
            cout<<"*";
        } cout<<endl;

        cout<<"*";
        for(int j=1; j<(n-1);j++){
            cout<<" ";
        }
        cout<<"*";

          for(int j=1; j<=n; j++){
            cout<<"*";
        } cout<<endl;
    }

}