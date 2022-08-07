 // Example for checking whether duplicate element is present or not.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool containsDuplicate(vector <int> d){
    sort(d.begin(),d.end());
    int s=d.size();
    int p=0; int q=1;
   while (q!=s)
   {
    if(d[p]==d[q]){
     return 1;
    }
    p++;q++;
   }
 return false;
}

int main(){
    vector <int> v={5};
    vector <int> v2={5,7,2,3,9};
    bool val=containsDuplicate(v);
    cout<<val;

}