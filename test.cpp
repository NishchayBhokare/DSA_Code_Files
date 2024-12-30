#include<bits/stdc++.h>
using namespace std;


int main() {
    
    int t;
    cin>>t;
    while(t--){

        int n, m;
        cin>>n>>m;

        vector<string>vec(n);
        for(int i=0; i<n; i++){
           cin>>vec[i];
        }

        int sumLen=0, cnt=0;
        for(auto str:vec){
            int len = str.length();

            if(sumLen+len <= m){

                sumLen+=len;
                cnt++;
            }
            else break;
        }
           

        cout<<cnt<<endl;
    }

    return 0;
}


