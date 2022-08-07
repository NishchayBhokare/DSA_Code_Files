#include<iostream>
#include<array>
// #include<algorithm>
// #include<iterator>
using namespace std;

int main(){
    array<int,3> arr2={4,5};
    // cout<<arr2[0]<<endl;  
    array<int,3> arr1;
    arr1={10,2,3};
// cout<<sizeof(arr2)<<endl;

    // cout<<arr1.front();
    // cout<<arr1.back();
    // cout<<arr1.size();
    // arr1.fill(2);
    // arr1.swap(arr2);
    // sort(arr1.begin(),arr1.end()); //array gets sorted.
    // for(int i=0;i<arr1.size();i++){
    //     cout<<arr1.at(i);
    // }

      // for(int i:arr1){  //another method for iterating over the array.
      //   cout<<i;
      // }

    // array<int,3>:: iterator it =arr1.begin();

    // while (it !=arr1.end())
    // {
    //     /* code */
    //     cout<<*it<<" ";
    //     it++;
    // }

    for(auto it=arr1.begin();it!=arr1.end();it++){
      cout<<*it<<" ";
    }
      
    // cout<<*it;

    return 0;
}