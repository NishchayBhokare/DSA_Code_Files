#include<iostream>
#include<vector>
using namespace std;

int main(){
    string str="abcda";
    vector<int>v(26,0);
    int i=0;
    while(i < str.length()){
        int index = (str[i] - 'a');
        v[index]++;
        i++;
    }

    int maxOccur = v[0];
    int maxIndex = 0;
    for(int i=1; i<v.size(); i++){
        if(v[i] > maxOccur ) maxIndex=i;
       
    }
    char ans = 'a' + maxIndex;
    cout<<ans;
return 0;
}