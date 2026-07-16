#include<bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin>>t;

    while(t--){
         
        string s;
        int n;
        cin>>n;
        cin>>s;

        int len=0, maxTime=0;
        for(int i=0; i<s.length(); i++){
            
            if(s[i] == '#')
                len++;
            
            else{
                maxTime = max(maxTime, (len+1)/2);
                len = 0;
            }
        }

        if(len > 0)  maxTime = max(maxTime, (len+1)/2);

        cout<<maxTime<<endl;
    }   


    return 0;
}