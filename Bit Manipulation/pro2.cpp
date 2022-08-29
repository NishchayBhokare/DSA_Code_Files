#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v1={1,2};
    vector<int> v2={4,5,6};
    int n1=v1.size(),n2=v2.size();
    // cin>>n1>>n2;
    // for(int i=0; i<n1; i++){
    //     int temp;
    //     cin>>temp;
    //     v1.push_back(temp);
    // }
    //  for(int j=0; j<n2; j++){
    //     int temp;
    //     cin>>temp;
    //     v2.push_back(temp);
    // }
    vector<int> ans=v1;
    for(int j=0; j<n2; j++){
        ans.push_back(v2[j]);
    }
    sort(ans.begin(),ans.end());

    vector<int>dup;
    for(int i=0; i<ans.size();){
        if(ans[i] == ans[i+1]) i++;
        else{
            dup.push_back(ans[i]);
            i++;
        }
    }
    // cout<<endl;
    // for(auto i: dup) cout<<i<<" ";
    // // cout<<"size is " <<dup.size()<<" "<<dup[0]<<" "<<dup[dup.size()-1];
    if(dup.size() % 2 == 0){
        float first=dup[(dup.size()/2) -1];
        float second=dup[dup.size()/2];
        cout<<((first+second)/2);
    }
    else {
        float third=dup[dup.size()/2];
        cout<<(third/1.0)<<endl;
    }
}